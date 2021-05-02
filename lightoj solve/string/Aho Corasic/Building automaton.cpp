void build_fail()
{
    queue q;
    int i;
    for(int i = 0; i < 26; i++)
    {
        if(ch[0][i])
            q.push(ch[0][i]);
    }
 
    int r,u,v;
    while(!q.empty())
    {
        r=q.front();
        q.pop();
        for(int c = 0; c < 26; c++)
        {
            u=ch[r][c];
            if(!u)
                continue;
            q.push(u);
            v=f[r];
            while(v && ch[v][c]==0)
                v=f[v];
            f[u]=ch[v][c];
        }
    }
}
void search(string s)
{
    int j=0;
    for(int i = 0; i < s.size(); i++)
    {
        int c=s[i]-'a';
        while(j && ch[j][c]==0)
            j=f[j];
        j=ch[j][c];
        int temp=j;
        while(temp)
        {
            num[temp]++;
            temp=f[temp];
        }
    }
}