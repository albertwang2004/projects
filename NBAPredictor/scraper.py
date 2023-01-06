import requests
from bs4 import BeautifulSoup
import pandas as pd
import re

from datetime import datetime
import time



###################################################################
# 1. process how recent the data is and how far we need to update #
###################################################################

year, month, day = [int(x) for x in open("./data/recency.dat", "r").read().split()]
currentYear, currentMonth, currentDay = datetime.now().year, datetime.now().month, datetime.now().day

daysPerMonth = (0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)

def incrementDay():
    global year, month, day
    day += 1

    # roll over the month if we have to
    isFebruaryLeapYear = (month == 2) and (year % 4 == 0)
    
    if ((isFebruaryLeapYear and day == 30)
    or (not isFebruaryLeapYear and daysPerMonth[month] < day)):
        month += 1
        day = 1

    # roll over the year if we have to
    if (month == 13):
        year += 1
        month = 1



#########################################
# 2. open and process player dictionary #
#########################################

playerUserList = open("./data/playerIDs.dat", "r", encoding="utf-8")

playerIDtoDisplayName = dict({})

for line in playerUserList:
    playerID, playerName = playerUserList.split(':')
    if playerID == None:
        continue
    playerIDtoDisplayName[playerID] = playerName

playerUserList.close()


###########################################################
# 3. function to scrape and append all games from one day #
###########################################################

siteURL = "https://www.basketball-reference.com"
gameData = open("./data/nba.dat", "a", encoding="utf-8")

def scrapeGame(url, visitor, home):

    global playerIDtoDisplayName
    parsed = BeautifulSoup(requests.get(url).text,'html.parser')
    
    visitorBoxScore = parsed.find_all("table", id = "box-{t}-game-basic".format(t = visitor))[0]
    visitorHead = visitorBoxScore.find("thead")
    columns = [x for x in [field.get("data-stat") for field in visitorHead.find_all("th")] if x != "header_tmp" and x != "player" and x != None]
    
    visitorBoxDict = {}
    
    visitorRows = visitorBoxScore.find_all("tr", {"class" : None})[1:]
    for visitorRow in visitorRows:
        if visitorRow.class_ == "thead":
            continue
        key = visitorRow.find("th")
        playerName = key.get("csk")
        playerID = key.get("data-append-csv")

        if playerID != None:
            playerIDtoDisplayName[playerID] = playerName

        curr = {}
        for field in columns:
            stat = visitorRow.find("td", {"data-stat" : field})
            if stat == None:
                continue
            value = stat.text
            curr[field] = value

        if len(curr):
            visitorBoxDict[playerID] = curr
    
    homeBoxScore = parsed.find_all("table", id = "box-{t}-game-basic".format(t = home))[0] 
    homeBoxDict = {}
    
    homeRows = homeBoxScore.find_all("tr", {"class" : None})[1:]
    for homeRow in homeRows:
        if homeRow.class_ == "thead":
            continue
        key = homeRow.find("th")
        playerName = key.get("csk")
        playerID = key.get("data-append-csv")
        
        if playerID != None:
            playerIDtoDisplayName[playerID] = playerName

        curr = {}
        for field in columns:
            stat = homeRow.find("td", {"data-stat" : field})
            if stat == None:
                continue
            value = stat.text
            curr[field] = value

        if len(curr):
            homeBoxDict[playerID] = curr
            
    gameData.write(url.split('/')[-1][:8] + '\n')
    gameData.write(visitor + '\n')
    gameData.write(','.join(columns) + '\n')
    for row in visitorBoxDict:
        toWrite = row
        if toWrite == None:
            toWrite = "team"
        for field in columns:
            toWrite += ',' + visitorBoxDict[row][field]
        gameData.write(toWrite + '\n')
    gameData.write(home + '\n')
    gameData.write(','.join(columns) + '\n')
    for row in homeBoxDict:
        toWrite = row
        if toWrite == None:
            toWrite = "team"
        for field in columns:
            toWrite += ',' + homeBoxDict[row][field]
        gameData.write(toWrite + '\n')
        

def scrapeDay():
    # compute the corresponding url
    dayURL = siteURL + "/boxscores/?month={m}&day={d}&year={y}".format(m = month, d = day, y = year)

    # parse page html
    parsed = BeautifulSoup(requests.get(dayURL).text,'html.parser')

    # find all elements corresponding to 'game summaries'
    gameList = parsed.find_all("div",class_="game_summary")

    for game in gameList:
        # prevent getting banned >:(
        time.sleep(0.4)
        
        # find the corresponding href for each box score
        links = game.find_all("a")
        boxScoreLink = siteURL + links[1]['href']


        # do some string manipulation to find team ID, and scrape!
        scrapeGame(boxScoreLink, links[0]['href'].split("/")[2], links[2]['href'].split("/")[2])



###########################
# 4. main loop of program #
###########################

while ((year, month, day) != (currentYear, currentMonth, currentDay)):
    incrementDay()
    scrapeDay()
    print("loaded all data from {m}/{d}/{y}".format(m = month, d = day, y = year))

    
writeIDs = open("./data/playerIDs.dat", "w", encoding = "utf-8")
for playerID in playerIDtoDisplayName:
    if playerID != None:
        writeIDs.write(playerID + ':' + playerIDtoDisplayName[playerID] + '\n')
writeIDs.close()

with open("./data/recency.dat", "w") as lastDate:
    lastDate.write("{y} {m} {d}".format(y = year, m = month, d = day))
