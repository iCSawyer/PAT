# include<iostream>
# include<string.h>
# include<vector>
# include<algorithm>
using namespace std;

struct Student{
    char id[15];
    int score;
    int loc;
    int loc_rk;
    int final_rk;
};

bool cmp(Student s1, Student s2)
{ 
    if(s1.score != s2.score) return s1.score > s2.score; 
    else return strcmp(s1.id, s2.id) < 0;
}

int main()
{
    int T;
    int location = 0;
    scanf("%d", &T);
    
    vector<Student> all_stu;
    while(T--)
    {
        location ++; 
        int num;
        scanf("%d", &num);
        
        vector<Student> stu;
        for (int i = 0; i < num; i ++)
        {
            char id[15]; int score;
            scanf("%s%d", id, &score);
            Student s;
            strcpy(s.id, id);
            s.score = score;
            s.loc = location;
            s.final_rk = s.loc_rk = 0;
            stu.push_back(s);
        }
        sort(stu.begin(), stu.end(), cmp);
        
        int rk = 1;
        for (vector<Student>::iterator it = stu.begin(); it != stu.end(); it++)
        {
            if(it == stu.begin() || (*it).score != (*(it - 1)).score)
                (*it).loc_rk = rk;
            else
                (*it).loc_rk = (*(it - 1)).loc_rk;
            rk ++;
            all_stu.push_back(*it);
        }
    }
	
	    
    sort(all_stu.begin(),all_stu.end(),cmp);

    int rk = 1;
    for (vector<Student>::iterator it = all_stu.begin(); it != all_stu.end(); it++)
    {
        if(it == all_stu.begin() || (*it).score != (*(it - 1)).score)
            (*it).final_rk = rk;
        else
            (*it).final_rk = (*(it - 1)).final_rk;
        rk ++;

    }

    printf("%d\n",all_stu.size());
    for (vector<Student>::iterator it = all_stu.begin(); it != all_stu.end(); it++)
    {
        printf("%s %d %d %d\n", it->id, it->final_rk, it->loc, it->loc_rk);
    }
    return 0;
}
