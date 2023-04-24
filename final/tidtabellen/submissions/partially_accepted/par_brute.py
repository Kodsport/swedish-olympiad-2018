import sys

def tosec(s):
    return int(s[:2])*3600+int(s[3:5])*60+int(s[6:8])

def fromsec(t):
    h=t/3600
    m=(t%3600)/60
    s=t%60
    return "%d%d:%d%d:%d%d"%(h/10,h%10,m/10,m%10,s/10,s%10)

Z=24*60*60
lines=sys.stdin.readlines()
bus=[int(x) for x in lines[1].split()]
tab=[tosec(x) for x in lines[2:]]
N=len(bus)
M=len(tab)
pos=[]
for si in range(M):
    st=(tab[si]-bus[0])%Z
    space=Z if M==1 else (tab[si]-tab[(si-1)%M])%Z
    if space>bus[0]:
        ok=True
        for i in range(1,N):
            ti=(si+i)%M
            if(bus[i]-bus[i-1]>Z) or (((st+bus[i])%Z)!=(tab[ti]%Z)):
                ok=False
                break
        if ok: pos.append(st)
if len(pos)==0:
    print("fel")
else:
    pos.sort()
    print(" ".join([fromsec(x) for x in pos]))

