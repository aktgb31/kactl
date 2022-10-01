/**
 * Author: Amit Kumar
 * Date: 2022-10-01
 * Description: Offline trees
 * Time: O(nlogn) Amortized
 */

int color[MAXN];
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], ti[MAXN];

int cnt[MAXN];
long long sum[MAXN]; // sum of elements with frequency
long long ans[MAXN];

int sz[MAXN];

int mx = 0;
int timer = 0;

void dfs(int u, int p)
{
    sz[u] = 1;
    ti[timer] = u;
    tin[u] = timer++;
    for (const auto &it : adj[u])
        if (it != p)
            dfs(it, u), sz[u] += sz[it];
    tout[u] = timer;
}

void add(int x)
{
    sum[cnt[color[x]]] -= color[x];
    if (cnt[color[x]] == mx)
        ++mx;
    ++cnt[color[x]];
    sum[cnt[color[x]]] += color[x];
}

void remove(int x)
{
    sum[cnt[color[x]]] -= color[x];
    if (cnt[color[x]] == mx && sum[cnt[color[x]]] == 0)
        --mx;
    --cnt[color[x]];
    sum[cnt[color[x]]] += color[x];
}

void dfsMerge(int u, int p, int keep)
{
    int Max = -1, bigChild = -1;
    for (const auto &it : adj[u])
        if (it != p && sz[it] > Max)
            Max = sz[it], bigChild = it;

    for (const auto &it : adj[u])
        if (it != p && it != bigChild)
            dfsMerge(it, u, 0);

    if (bigChild != -1)
    {
        dfsMerge(bigChild, u, 1);
    }
    add(u);
    for (const auto &it : adj[u])
        if (it != p && it != bigChild)
            for (int i = tin[it]; i < tout[it]; i++)
                add(ti[i]);

    ans[u] = sum[mx];
    if (!keep)
    {
        for (int i = tin[u]; i < tout[u]; i++)
            remove(ti[i]);
    }
}
