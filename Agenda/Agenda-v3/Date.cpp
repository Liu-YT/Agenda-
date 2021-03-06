#include "Date.hpp"
#include <string>
#include <cstdio>
#include <cstring>
using std::string;

Date::Date(){
	m_year = m_month = m_day = m_hour = m_minute = 0;
}

Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute){
	m_year = t_year;
	m_month = t_month;
	m_day = t_day;
	m_hour = t_hour;
	m_minute = t_minute;
}

Date::Date(const std::string &dateString){
	m_year = m_month = m_day = m_hour = m_minute = 0;
	if(dateString.size() != 16) 	return;
	if(dateString[4] != '-' || dateString[7] != '-'|| dateString[10] != '/' || dateString[13] != ':') return;
	for(int i = 0;i < dateString.size();i++) 
		if(i == 4 || i == 7 || i == 10 || i == 13)	continue;
		else
			if(dateString[i] > '9' || dateString[i] < '0')	return;
	m_year = stoi(dateString.substr(0,4));
	m_month = stoi(dateString.substr(5,2));
	m_day = stoi(dateString.substr(8,2));
	m_hour = stoi(dateString.substr(11,2));
	m_minute = stoi(dateString.substr(14,2));
	if(!isValid(*this))	m_year = m_month = m_day = m_hour = m_minute = 0;
}

int Date::getYear(void) const{ return m_year; }

void Date::setYear(const int t_year){ m_year = t_year;}

int Date::getMonth(void) const { return m_month; }

void Date::setMonth(const int t_month){ m_month = t_month; }

int Date::getDay(void) const{ return m_day; }

void Date::setDay(const int t_day){ m_day = t_day; }

int Date::getHour(void) const{ return m_hour; }

void Date::setHour(const int t_hour){ m_hour = t_hour; }

int Date::getMinute(void) const{ return m_minute; }

void Date::setMinute(const int t_minute){ m_minute = t_minute; }

bool Date::isValid(const Date &t_date){
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(t_date.m_year < 1000 || t_date.m_year > 9999 || t_date.m_month > 12 || t_date.m_month < 1 || t_date.m_hour < 0 || t_date.m_hour > 23 || t_date.m_minute < 0 || t_date.m_minute > 59 || t_date.m_day < 1) return false;
	if(t_date.m_year % 400 == 0 || (t_date.m_year % 100 != 0 && t_date.m_year % 4 == 0))
		month[2] = 29;
	if(t_date.m_day > month[t_date.m_month])	return false;
	else return true;	
}

Date Date::stringToDate(const std::string &dateString){
	Date t_date;
	t_date.m_year = t_date.m_month = t_date.m_day = t_date.m_hour = t_date.m_minute = 0;
	if(dateString.size() != 16) 	return t_date;
	if(dateString[4] != '-' || dateString[7] != '-'|| dateString[10] != '/' || dateString[13] != ':') return t_date;
	for(int i = 0;i < dateString.size();i++) 
		if(i == 4 || i == 7 || i == 10 || i == 13)	continue;
		else
			if(dateString[i] > '9' || dateString[i] < '0')	return t_date;
	t_date.m_year = stoi(dateString.substr(0,4));
	t_date.m_month = stoi(dateString.substr(5,2));
	t_date.m_day = stoi(dateString.substr(8,2));
	t_date.m_hour = stoi(dateString.substr(11,2));
	t_date.m_minute = stoi(dateString.substr(14,2));
	if(!isValid(t_date))	t_date.m_year = t_date.m_month = t_date.m_day = t_date.m_hour = t_date.m_minute = 0;
	return t_date;
}

std::string Date::dateToString(const Date &t_date){
	if(!isValid(t_date)){
		string st = "0000-00-00/00:00";
		return st;
	}
	string str = "";
	char s[20];
	snprintf(s,20,"%04d-%02d-%02d/%02d:%02d",t_date.m_year,t_date.m_month,t_date.m_day,t_date.m_hour,t_date.m_minute);
	str = string(s);
	return s;
}

Date& Date::operator=(const Date &t_date){
	m_year = t_date.m_year;
	m_month = t_date.m_month;
	m_day = t_date.m_day;
	m_hour = t_date.m_hour;
	m_minute = t_date.m_minute;
	return (*this);
}

bool Date::operator==(const Date &t_date) const{
	return dateToString(*this) == dateToString(t_date);
}

bool Date::operator>(const Date &t_date) const{
	return dateToString(*this) > dateToString(t_date);
}

bool Date::operator<(const Date &t_date) const{
	return dateToString(*this) < dateToString(t_date);
}

bool Date::operator>=(const Date &t_date) const{
	return dateToString(*this) >= dateToString(t_date);
}

bool Date::operator<=(const Date &t_date) const{
	return dateToString(*this) <= dateToString(t_date);
}
