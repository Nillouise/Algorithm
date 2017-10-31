out);
    ios::sync_with_stdio(false);//这行应该注释掉，不能不能混用cin和printf

    for(int kase=1;;kase++)
    {

        cin>>n;
        if(n==0)break;

        if(kase!=1)cout<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>buf[i].x>>buf[i].y>>buf[i].width>>buf[i].depth>>buf[i].height;
            buf[i].id=i+1;
            X[i*2]=buf[i].x;
            X[i*2+1]=buf[i].x+buf[i].width;
        }

        sort(X,X+2*n);
        sort(buf,buf+n);
        int m = unique(X,X+2*n)-X;



    printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, buf[0].id);

        for(int i=1;i<n;i++)
        {
            int flag= 0;
            for(int j=1;j<m;j++)
            {
                if(visiable(i,X[j]/2+X[j-1]/2))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                cout<<" "<<buf[i].id;
            }
        }
        cout<<endl;
    }



    return 0;
}
