#include <bits/stdc++.h>
using namespace std;
const long maxn = 1e6;
int a[maxn],b[maxn],c[maxn+1],maxx,minn;
string s,x;
void inp(){
    cin >> s;
    cin >> x;
    for(long i = s.length()-1; i >= 0; i--)
        a[s.length()-1-i] = s[i]-48;
    for(long i = x.length()-1; i >= 0; i--)
        b[x.length()-1-i] = x[i]-48;
    maxx = max(s.length(),x.length());
    minn = min(s.length(),x.length());
}
void pluss(){
    int t,debt = 0,BASE = 10;
    for(long i = 0; i < maxx; i++){
        t = a[i]+b[i];
        c[i] = t%BASE + debt;
        debt = t/BASE;
    }
    if (debt > 0)
        cout << debt;
    for(int i = maxx-1; i >= 0; i--)
        cout << c[i];
}
void minuss(){
    int debt = 0, BASE = 10,t;
    for(int i = 0; i < maxx; i++)
        if (a[i] < b[i]+debt){
            t = a[i] + BASE;
            c[i] = t-b[i]-debt;
            debt = 1;
        }else{
            c[i] = a[i]-b[i];
            debt = 0;
        }
    int j = maxx-1;
    while (c[j] == 0)
        j--;
    for(int i = j; i >= 0; i--)
        cout << c[i];
}
void multi(){
    int BASE = 10;
    stack <int> z;
    for(int i = 0; i < s.length();i++)
        for(int j = 0; j < x.length();j++)
            c[i+j] += a[i]*b[j];
    for(int i = 0; i < maxx+minn; i++){
        z.push(c[i]%BASE);
        c[i+1] += c[i]/BASE;
    }
    while (z.top()==0)
        z.pop();
    while (z.size()){
        cout << z.top();
        z.pop();
    }
}
void Mod(string x){
    long long q = 0,t = 0, BASE = 10;
    for(int i = 0; i < x.length(); i++)
        q = q*10 + (x[i]-48);
    for(int i = s.length()-1; i >= 0; i--)
        t = (t*BASE+a[i])%q;
    cout << t << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    pluss();
    //minuss();
    //multi();
    //Mod(x);
    return 0;
}

