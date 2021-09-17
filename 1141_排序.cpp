// 16.31
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
struct college {
    string name;
    double score = 0;
    int people = 0;
}College[N];
unordered_map<string, int> s2i;
int cIndex = 0;

int change(string name) {
    if(s2i.find(name) != s2i.end()) return s2i[name];
    s2i.insert(pair<string, int>(name, cIndex));
    College[cIndex].name = name;
    return cIndex ++;
}

bool cmp(college a, college b) {
    if((int)a.score == (int)b.score && a.people == b.people) return a.name < b.name;
    if((int)a.score == (int)b.score) return a.people < b.people;
    return (int)a.score > (int)b.score;
}

string lowercase(string name) {
    for(int i = 0; i < name.size(); i ++)
        if(name[i] >= 'A' && name[i] <= 'Z')
            name[i] = name[i] - 'A' + 'a';
    return name;
}

int main() {
    string id, name;
    int n, k, rk, people; double score;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> id >> score >> name;
        name = lowercase(name);
        k = change(name);
        College[k].people ++;
        if(id[0] == 'A') College[k].score += score;
        else if(id[0] == 'T') College[k].score += score * 1.5;
        else College[k].score += score / 1.5;
    }
    sort(College, College + cIndex, cmp);
    int lastScore = -1; int lastRk = -1;
    cout << cIndex << endl;
    for(int i = 0; i < cIndex; i ++){
        name = College[i].name;
        double final = College[i].score;
        people = College[i].people;
        if(lastScore == (int)final) rk = lastRk;
        else rk = i + 1;
        printf("%d %s %d %d\n", rk, name.c_str(), (int)final, people);
        lastScore = (int)final;
        lastRk = rk;
    }
    return 0;
}