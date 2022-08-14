for (int i = 0 ; (1ll << i) <= n ; i++){
   if ((n >> i) & 1) cnt++;
}
if (cnt == 1) cout << "YES";
else cout << "NO";
