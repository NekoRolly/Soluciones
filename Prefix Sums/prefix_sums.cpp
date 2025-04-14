void solve(){

    int n;
    cin >> n;

    int a[n+1];
    int pr[n+1];

    // [-, 7, 3, 4, 1, 4]
    // [0, 7, 10, 14, 15, 19]
    pr[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pr[i] = pr[i-1] + a[i];   
    }

    int m;
    cin >> m;
    int b[n+1][m+1];
    int pr2d[n+1][m+1];

    for (int i=0; i<=n; i++)
        pr2d[i][0] = 0;

    for (int j=0; j<=m; j++)
        pr2d[0][j] = 0;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            cin >> b[i][j];
            pr2d[i][j] = pr2d[i-1][j] + pr2d[i][j-1] - pr2d[i-1][j-1] + b[i][j];
        }

    cout << "pr: ";
    for (int i=0; i<=n; i++)
        cout << pr[i] << " ";
    cout << "\n\n";

    cout << "pr2d: \n";
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            cout << pr2d[i][j] << "\t";
        }
        cout << "\n";
    }
}