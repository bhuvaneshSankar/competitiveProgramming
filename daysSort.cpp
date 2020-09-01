#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getYear(string s)
{
    string yearString = s.substr(7, 4);
    int year = 0;
    for (char ch : yearString)
    {
        year = year * 10 + (ch - '0');
    }
    return year;
}
int getMonth(string s)
{
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unordered_map<string, int> dateMap;
    int val = 1;
    for (string month : months)
    {
        dateMap.insert({month, val});
        ++val;
    }
    string monthString = s.substr(3, 3);
    int m = dateMap[monthString];
    return m;
}
int getDay(string s)
{
    string dayString = s.substr(0, 2);
    int day = 0;
    for (char ch : dayString)
    {
        day = day * 10 + (ch - '0');
    }
    return day;
}
bool comp(string s1, string s2)
{

    int y1 = getYear(s1);
    int y2 = getYear(s2);
    int m1 = getMonth(s1);
    int m2 = getMonth(s2);
    int d1 = getDay(s1);
    int d2 = getDay(s2);
    if (y1 < y2)
    {
        return true;
    }
    if (y1 == y2 && m1 < m2)
    {
        return true;
    }
    if (y1 == y2 && m1 == m2 && d1 < d2)
    {
        return true;
    }
    return false;
}
void sortDates(vector<string> &dates)
{
    sort(dates.begin(), dates.end(), comp);
}
int main()
{
    // vector<string> dates = {"21-Aug-2020", "05-Jan-2021", "13-Feb-2020", "01-Dec-2019", "05-Mar-2020", "01-Aug-2020", "13-Feb-2020"};
    vector<string> dates = {"24 Jul 2017", "25 Jul 2017", "11 Jun 1996",
                            "01 Jan 2019", "12 Aug 2005", "01 Jan 1997"};
    sortDates(dates);
    for (string date : dates)
    {
        cout << date << " ";
    }
}