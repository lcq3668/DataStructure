`$c[i][j] $` 表示 `$ s_{i,j} $`的最长回文子序列的长度

`$
c[i][j]=\begin{cases}
1,\quad i=j \\\\
2,\quad j=i+1 \quad and \quad s[i]=s[j] \\\\
c [i+1][j-1] +2 , j > i+1 \quad and \quad s[i]=s[j] \\\\
max\{c [i+1][j],c [i][j-1]\}, j > i+1 \quad and \quad s[i] \neq s[j]
\end{cases}
$`