//DEEPANSHU SAXENA(saxenad765)
#include <bits/stdc++.h>
#define ll long long
#define arrayelem(x,n) (x,x+n)
#define vector(v) (v.begin(),v.end())
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define ip(x) cin>>x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define odd(x) (x&1)
#define even(x) (!x&1)
#define fbei(i,x,y,z) for(i=x;i<=y;i+=z)
#define fbe(i,x,y) for(ll i=x;i<=y;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GCD(x,y) __gcd(x,y)
using namespace std;
//Deepanshu Saxena
inline void Filehandling()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
inline void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
vector<ll> vector_in(ll n)
{
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	cin>>v[i];
	return v;
}
void vector_out(vector<ll> v)
{
	for(ll i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
}
ll vector_sum(vector<ll> v)
{
	ll sum;
	for(ll i=0;i<v.size();i++)
	sum+=v[i];
	return sum;
}
int main()
{
	//Filehandling();
	ll t, n, mid, z2, z;
	cin >> t;
	ll r = 1;
	while (t--)
	{
		cin >> n;
		mid = n/2;
		if (n % 2)
			mid++;
		vector <ll> s(n);
		char u;
		for (ll i = 0; i < n; ++i)
		{
			cin >> u;
			s[i] = u - '0';
		}
		z = 0;
		f(i,mid)
			z += s[i];
		z2 = z;
		fbe(i,mid,n-1)
		{
			z = z + s[i] - s[i-mid];
			if (z > z2)
				z2 = z;
		}
		cout << "Case #" << r++ << ": " <<  z2 << endl;
	}
}