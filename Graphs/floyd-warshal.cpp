const ll OO = LONG_LONG_MAX;

void floyd(){
  d[v][u] = OO;
	d[v][v] = 0;
  for (int k = 1 ; k <= n ; k++){
    for (int i = 1 ; i <= n ; i++){
      for (int j = 1 ; j <= n ; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
      }
    }
  }
}
