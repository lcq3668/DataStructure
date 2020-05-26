本题用动态规划解决

设 `$c[i][j]$` 有两种取值：True and False。当`$c[i][j]$` 是 True 时,表示子串`$s_{i,j}$`是 回文;当`$c[i][j]$` 是 False 时,表示子串`$s_{i,j}$` 不是 回文。

`$
c[i][j]=\begin{cases}
True,\quad i=j \\\\
True,\quad j=i+1 \quad and \quad s[i]=s[j] \\\\
False, \quad j=i+1 \quad and \quad s[i] \neq s[j] \\\\
True,\quad j > i+1 \quad and \quad c[i+1][j-1] = True \quad and s[i]=s[j]\\\\
False, \quad other \quad situation 
\end{cases}
$`

构建好 `$c$` 后,按子串长度从大到小，访问c[i][j]，遇到True 则返回对应的子串