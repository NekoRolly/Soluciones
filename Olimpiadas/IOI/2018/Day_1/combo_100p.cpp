#include<bits/stdc++.h>
#include"combo.h"
using namespace std;

string guess_sequence(int n){
    string s, p;

    int pnts = press("XY");
    if (pnts == 0){
        pnts = press("A");
        if (pnts == 1)
            s = "A";
        else
            s = "B";
    }
    else{
        pnts = press("X");
        if (pnts == 1)
            s = "X";
        else
            s = "Y";
    }

    string t;
    for (int c : {'A', 'B', 'X', 'Y'})
        if (c != s[0])
            t += c;

    while (s.size() < n-1){
        p = s + t[0] + t[0];
        p += s + t[0] + t[1];
        p += s + t[0] + t[2];
        p += s + t[1];
        pnts = press(p);
        if (pnts == s.size()+2)
            s += t[0];
        else if (pnts == s.size()+1)
            s += t[1];
        else
            s += t[2];
    }

    if (s.size() < n){
        pnts = press(s+"X"+s+"Y");
        if (pnts == n-1){
            pnts = press(s+"A");
            if (pnts == n)
                s += "A";
            else
                s += "B";
        }
        else{
            pnts = press(s+"X");
            if (pnts == n)
                s += "X";
            else
                s += "Y";
        }      
    }

    return s;
}