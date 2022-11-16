import requests
from bs4 import BeautifulSoup
import pandas as pd
import re

from datetime import datetime



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

playerUserList = open("./data/playerIDs.dat", "r")
playerNameList = open("./data/playerNames.dat", "r")

playerIDs = {}
playerIDtoDisplayName = {}

currLine = 0
# add players into dictionary
for line in playerUserList:
    playerIDs[line] = currLine
    currLine += 1



###########################################################
# 2. function to scrape and append all games from one day #
###########################################################

siteURL = "https://www.basketball-reference.com"

def scrapeGame(url, visitor, home):
    # parse html
    parsed = BeautifulSoup(requests.get(url).text,'html.parser')

    print(url,visitor,home)    

gameData = open("./data/nba.dat", "a")
def scrapeDay():
    # compute the corresponding url
    dayURL = siteURL + "/boxscores/?month={m}&day={d}&year={y}".format(m = month, d = day, y = year)

    # parse page html
    parsed = BeautifulSoup(requests.get(dayURL).text,'html.parser')

    # find all elements corresponding to 'game summaries'
    gameList = parsed.find_all("div",class_="game_summary")

    for game in gameList:
        # find the corresponding href for each box score
        links = game.find_all("a")
        boxScoreLink = siteURL + links[1]['href']

        # do some string manipulation to find team ID, and scrape!
        scrapeGame(boxScoreLink, links[0]['href'].split("/")[2], links[2]['href'].split("/")[2])



###########################
# 3. main loop of program #
###########################

while ((year, month, day) != (currentYear, currentMonth, currentDay)):
    incrementDay()
    scrapeDay()
    print("loaded all data from {m}/{d}/{y}".format(m = month, d = day, y = year))
