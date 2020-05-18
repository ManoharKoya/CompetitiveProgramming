/********************************
*** ******** ********** *********
*** * ****** ********* * ********
*** ** ***** ******** *** *******
*** *** **** ******* ***** ******
*** **** *** ****** ******* *****
*** ***** ** ***** +++++++++ ****
*** ****** * **** *********** ***
*** *******  *** ************* **
*** ******** ** *************** *
**********_**********************
* |   /  / \  \     /    /\     *
* |  /  |   |  \   /    /  \    *
* | /   |   |   \ /    /    \   *
* |+\   |   |    |    /______\  *
* |  \  |   |    |   |        | *
* |   \  \_/     |   |        | *
********************************/
#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define KING 1000000002
#define queen 1000002
#define fi first
#define se second
#define se second
#define lsb(i) (i & -i)
#define nl cout<<'\n'
#define TEST cout<<"TEST",nl
#define all(a) a.begin(), a.end()
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define P pair<lli,pr>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;

lli r,c;

bool ck(vector<vector<char> > h , char curr ,string a[]){
    vector<vector<char> > b = h;
    for(lli i = r-1;i>=0;i--){
        for(lli j = 0;j<c;j++){
            if(a[i][j] == curr){
            if(i+1 ==r || b[i+1][j] == ':'){
                    b[i][j] = ':' ; 
            }else{
                return false;
            }
            }
        }
    }
    return true;
}


void solve(){
    cin>>r>>c;
    string a[r];
    vector<vector<char> > b(r , vector<char>(c,'_'));
    NA(i,0,r) cin>>a[i];
    vector<bool> d(26 , false);
    vector<char>ans; string res = "";
    
    for(lli I = r-1;I>=0;I--){
        NA(i,0,c){
        if(d[a[I][i]-'A'] == 1){continue;}
        if(ck(b , a[I][i] , a) == true){
            NA(j,0,r){
                NA(k,0,c){
                    if(a[j][k] == a[I][i]){
                        b[j][k] = ':';
                    }
                }
            }
            d[a[I][i] -'A'] = true;
            ans.push_back(a[I][i]);
            res += a[I][i];
        }
    }
    for(lli i = c-1;i>=0;i--){
        if(d[a[I][i]-'A'] == true){continue;}
        if(ck(b , a[I][i] , a) == true){
            NA(j,0,r){
                NA(k,0,c){
                    if(a[j][k] == a[I][i]){
                        b[j][k] = ':';
                    }
                }
            }
            d[a[I][i] -'A'] = true;
            ans.push_back(a[I][i]);
            res+=a[I][i];
        }
    }
    }

    NA(i,0,r){
        NA(j,0,c){
            if(b[i][j] == '_'){
                cout<<(-1)<<"\n"; return;
            }
        }
    }
    for(char c : ans){
        cout<<c;
    }
    nl;
}

int main(){
    fastIO;
    lli t; cin>>t;
    NA(i,0,t) {
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
}