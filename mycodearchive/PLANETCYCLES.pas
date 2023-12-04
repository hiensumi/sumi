uses math;
const
  FINP='';
  FOUT='';
  MAXN=200000;
type
  list=^node;
  node=record
         u:longint;
         next:list;
       end;
var
  f1,f2:text;
  tt,sl,count,top,n:longint;
  d,ss,dd,sd,vao,ra,stack,xet,ke:array[1..MAXN] of longint;
  ds:array[1..MAXN] of list;
procedure add(u:longint; var a:list); inline;
var
  p:list;
begin
  new(p); p^.u:=u;
  p^.next:=a; a:=p;
end;
procedure openF; inline;
begin
  assign(f1,FINP); reset(f1);
  assign(f2,FOUT); rewrite(f2);
end;
procedure closeF; inline;
begin
  close(f1); close(f2);
end;
procedure inp; inline;
var
  i:longint;
begin
  read(f1,n);
  for i:=1 to n do read(f1,ke[i]);
end;
procedure dfs1(u:longint);
var
  v:longint;
begin
  tt:=1; ss[1]:=u;
  while tt>0 do
    begin
      u:=ss[tt]; dec(tt);
      if vao[u]=0 then
        begin
          inc(count);
          vao[u]:=count;
          xet[u]:=1;
        end;
      v:=ke[u];
      if xet[v]=0 then
        begin
          inc(tt); ss[tt]:=u;
          inc(tt); ss[tt]:=v;
        end
      else
        begin
          inc(count);
          ra[u]:=count;
        end;
    end;
end;
procedure dfs2(u:longint);
var
  k,v:longint;
begin
  tt:=1; ss[tt]:=u;
  while tt>0 do
    begin
      u:=ss[tt]; dec(tt);
      inc(top); stack[top]:=u;
      xet[u]:=1;
      v:=ke[u];
      if (xet[v]=1) then
        begin
          if (vao[v]<=vao[u]) and (ra[v]>=ra[u]) then
            begin
              inc(sl); sd[sl]:=0;
              repeat
                inc(sd[sl]);
                k:=stack[top]; dec(top);
                add(k,ds[sl]); dd[k]:=sl;
              until k=v;
            end;
        end
      else
        begin
          inc(tt); ss[tt]:=v;
        end;
    end;
end;
procedure dfs3(u:longint);
var
  v:longint;
begin
  tt:=1; ss[1]:=u;
  while tt>0 do
    begin
      u:=ss[tt]; dec(tt);
      v:=ke[u];
      if d[v]=0 then
        begin
          inc(tt); ss[tt]:=u;
          inc(tt); ss[tt]:=v;
        end
      else d[u]:=d[v]+1;
    end;
end;
procedure solve;
var
  i,u,x:longint;
begin
  fillchar(xet,sizeof(xet),0); count:=0;
  for i:=1 to n do
    if xet[i]=0 then dfs1(i);
  fillchar(xet,sizeof(xet),0);
  for i:=1 to n do
    if xet[i]=0 then
      begin
        top:=0;
        dfs2(i);
      end;
  fillchar(xet,sizeof(xet),0);
  for i:=1 to n do
    if dd[i]>0 then
      begin
        xet[i]:=1;
        d[i]:=sd[dd[i]];
      end;
  for i:=1 to n do
    if xet[i]=0 then
      begin
        dfs3(i);
        writeln(f2,d[i]);
      end
    else writeln(f2,d[i]);
end;
begin
  openF;
  inp;
  solve;
  closeF;
end.