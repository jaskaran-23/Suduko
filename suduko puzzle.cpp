#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <math.h>
#include <climits>
#include <string>
#include <cstring>
#include <iomanip>
#include <stack>
#include <queue>
#include <tuple>
#include <unordered_map>
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define ld long double
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define mii map<int,int>
#define mll map<ll,ll>
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define mspii map<string,pair<int,int>>
#define pll pair<ll,ll>
#define F first
#define S second
#define PI 3.1415926535
#define setbits(x) __builtin_popcount(x)
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x
#define mem(a,b) memset(a,b,sizeof(a))
#define endl '\n'
#define __gcd gcd
#define all(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define lb lower_bound
#define ub upper_bound
//typedef long long ll;
using namespace std;
/*bool prime[200000 + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    prime[1] = false;

    for (int p = 2; p * p <= 200000; p++) {

        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {

            // Set all multiples of p to non-prime
            for (int i = p * 2; i <= 200000; i += p)
                prime[i] = false;
        }
    }
}
ll pow1(ll a,ll b){
     ll ans=1;
     if(b==0)return ans;
     while(b>0){
          if(b&1==1)ans*=a;
          a*=a;
          b/=2;
     }
     return ans;
}

ll ncr(ll n,ll r)
{
    if(r > n - r)
          r = n - r;
    ll ans = 1;
    ll i;
 
    for(i = 1; i <= r; i++)
     {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}

*/

bool safe(vector<vector<ll>>&v, ll r,ll c,ll num){
    f(i,9){
        if(v[i][c]==num)return false;
    }
    f(i,9){
        if(v[r][i]==num)return false;
    }
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(v[row+(r-(r%3))][col+(c-(c%3))]==num)return false;
        }
    }
    if(v[r][c]==0)return true;
    else return false;
}

bool unassigned(vector<vector<ll>>&v,ll &r,ll &c){
    for(r=0;r<9;r++){
        for(c=0;c<9;c++){
            if(v[r][c]==0)return true;
        }
    }
    return false;
}

bool solve(vector<vector<ll>>&v){
    ll r=0,c=0;
    if(unassigned(v,r,c)==false)return true;
    for(ll num=1;num<=9;num++){
        if(safe(v,r,c,num)==true){
            v[r][c]=num;
        if(solve(v)==true)return true;
        v[r][c]=0;
     }
    }
    return false;

}



int main()
{

    //AUTHOR-JASKARAN
     //Thug-Life...
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output1.txt","w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll t;
     cin>>t;                                                     

     while(t--){
        vector<vector<ll>>v(9,vector<ll>(9,0));
        ll val;cin>>val;
        while(val--){
            ll r,c,val1;cin>>r>>c>>val1;
            v[r][c]=val1;
        }
        bool a=solve(v);
        if(a==true){
            f(i,9){
                f(j,9)cout<<v[i][j]<<" ";
                cout<<endl;
            }
        }
        else{
            cout<<"no solution exits"<<endl;
        }
        
     }
}
