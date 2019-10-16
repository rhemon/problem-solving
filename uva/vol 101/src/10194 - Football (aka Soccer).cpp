// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=98&page=show_problem&problem=1135

#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct Team {
    string name;
    int goals_scored;
    int goals_against;
    int points;
    int played;
    int wins;
};
bool comp(Team team1, Team team2) {
    int gd1 = team1.goals_scored - team1.goals_against;
    int gd2 = team2.goals_scored - team2.goals_against;
    if (team1.points > team2.points) {
        return true;
    } else if (team2.points > team1.points) {
        return false;
    } else if (team1.wins > team2.wins) {
        return true;
    } else if (team2.wins > team1.wins) {
        return false;
    } else if (gd1 > gd2){
        return true;
    } else if (gd2 > gd1) {
        return false;
    } else if (team1.goals_scored > team2.goals_scored) {
        return true;
    } else if (team2.goals_scored > team1.goals_scored) {
        return false;
    } else if (team1.played < team2.played) {
        return true;
    } else if (team2.played < team1.played) {
        return false;
    } else {
        string n1 = team1.name;
        string n2 = team2.name;
        transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
        transform(n2.begin(), n2.end(), n2.begin(), ::tolower);
        return n1 < n2;
    }
}
void get_parts(string match, string* n1, string* n2, int* g1, int* g2) {


    int i = 0;
    for (;i<match.size();i++){
        if(match[i] == '#') {
            i++;
            break;
        }
        n1->push_back(match[i]);
    }
    string goal;
    for(;i<match.size();i++){
        if(match[i] == '@') {
            i++;
            break;
        }
        goal.push_back(match[i]);
    }
    (*g1) = stoi(goal);
    string goal2;
    for(;i<match.size();i++){
        if(match[i] == '#'){
            i++;
            break;
        }
        goal2.push_back(match[i]);
    }
    (*g2) = stoi(goal2);
    for(;i<match.size();i++){
        n2->push_back(match[i]);
    }
}
int main() {
    // ofstream cout;
    // ifstream cin;
    // cout.open("o.txt");
    // cin.open("f.txt");

    int t;
    cin >> t;
    cin.ignore();
    for (int c = 0; c < t; c++) {
        string tournament;
        getline(cin, tournament);
        // cout << "Tournament" << tourname .nt << endl;
        //
        int nt;
        cin >> nt;

        map<string, int> team_index;
        vector<Team> teams(nt);
        cin.ignore();
        for (int i = 0; i < nt; i++) {
            string tn;
            getline(cin, tn);
            Team team;
            team.name = tn;
            team.goals_scored = 0;
            team.goals_against = 0;
            team.points = 0;
            team.played = 0;
            team.wins = 0;
            teams[i] = team;
            team_index.insert(pair<string,int>(tn, i));
        }
        int matches;
        cin >> matches;
        cin.ignore();
        for (int i =0; i < matches; i++) {
            string match;

            getline(cin, match);
            int g1, g2;
            string n1, n2;
            get_parts(match, &n1, &n2, &g1, &g2);
            // cout << n1 << endl;
            Team t1 = teams[team_index.at(n1)];
            Team t2 = teams[team_index.at(n2)];
            t1.played++;
            t1.goals_scored += g1;
            t1.goals_against += g2;
            t2.played++;
            t2.goals_scored += g2;
            t2.goals_against += g1;
            if (g1 > g2) {
                t1.points += 3;
                t1.wins++;
            } else if (g2 > g1) {
                t2.points += 3;
                t2.wins++;
            } else {
                t1.points++;
                t2.points++;
            }
            teams[team_index.at(n1)] = t1;
            teams[team_index.at(n2)] = t2;
        }
        sort(teams.begin(), teams.end(), comp);

        cout << tournament << endl;
        int count = 1;
        for (Team team : teams) {
            cout << count << ") ";
            cout << team.name << " ";
            cout << team.points << "p, ";
            cout << team.played << "g ";
            cout << "(" << team.wins << "-";
            cout << (team.points-(team.wins*3)) << "-";
            cout << team.played-((team.points-(team.wins*3))+team.wins) << "), ";
            cout << team.goals_scored - team.goals_against << "gd (" << team.goals_scored << "-" << team.goals_against;
            cout << ")" << endl;
            count++;
        }
        if (c < t-1) {
            cout << endl;
        }
    }
}
