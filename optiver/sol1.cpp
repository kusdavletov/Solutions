#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

const int N = 1000;

map <char, bool> was;
map <string, bool> was_pair;
map <char, int> val;
int x, y, n, in[N], out[N], root, cl[N];
vector<int > a[N];
char ch[N];
string s, str[N], col[N], ss, s1;

bool check(string s){
    if ((int)s.size() != 5)
        return true;
    if (s[0] != '(' || s[4] != ')')
        return true;
    if (!(s[1] >= 'A' && s[1] <= 'Z'))
        return true;
    if (!(s[3] >= 'A' && s[3] <= 'Z'))
        if (s[2] != ',')
            return true;
    return false;
}

bool dfs(int v){
    cl[v] = 1;
    for (int i = 0; i < a[v].size(); i++){
        int to = a[v][i];
        if (cl[to] == 0){
            if (dfs (to))
                return true;
        }
        else if (cl[to] == 1){
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

void dfs2(int v){
    cout << "(" << ch[v];
    for (char chr = 'A'; chr <= 'Z'; chr++){
        for (int i = 0; i < a[v].size(); i++){
            int to = a[v][i];
            if (ch[to] == chr)
                dfs2(to);
        }
    }
    cout << ")";
}

int main(){
    int cnt = 0, k = 0;
    getline(cin, ss);
    int ll = 0;
    for (int i = 0; i < ss.size(); i++){
        ++ll;
        if (ll > 6)
            ll = 1, s1 = "";
        if (ss[i] != ' ')
            s1 += ss[i];
        if (ll == 1 && (ss[i] != '('))
            cout << "E1", exit(0);
        if (ll == 2 && !(ss[i] >= 'A' && ss[i] <= 'Z'))
            cout << "E1", exit(0);
        if (ll == 3 && ss[i] != ',')
            cout << "E1", exit(0);
        if (ll == 4 && !(ss[i] >= 'A' && ss[i] <= 'Z'))
            cout << "E1", exit(0);
        if (ll == 5 && ss[i] != ')')
            cout << "E1", exit(0);
        if (ll == 6 && ss[i] != ' ')
            cout << "E1", exit(0);
        if (ll == 5)
            col[++k] = s1;
    }
    for (int i = 1; i <= k; i++){
        s = col[i];
        if (check(s)){
            printf("E1");
            exit(0);
        }
        if (!was[s[1]]){
            val[s[1]] = ++n;
            was[s[1]] = true;
        }

        if (!was[s[3]]){
            val[s[3]] = ++n;
            was[s[3]] = true;
        }
        x = val[s[1]];
        y = val[s[3]];
        ch[x] = s[1];
        ch[y] = s[3];

        a[x].push_back(y);

        out[x]++;
        in[y]++;
        str[++cnt] = s;
    }

    for (int i = 1; i <= cnt; i++){
        if (was_pair[str[i]]){
            printf("E2");
            exit(0);
        }
        was_pair[str[i]] = true;
    }
    for (int i = 1; i <= n; i++){
        if ((int)a[i].size() > 2){
            printf("E3");
            exit(0);
        }
    }

    for (int i = 1; i <= n; i++){
        if (root && !in[i])
            printf("E5"), exit(0);
        if (!in[i])
            root = i;
        if (in[i] > 1)
            cout << "E4", exit(0);
    }

    for (int i = 1; i <= n; i++){
        if (dfs(i)){
            cout << "E4";
            exit(0);
        }
    }
    dfs2(root);
    return 0;
}
