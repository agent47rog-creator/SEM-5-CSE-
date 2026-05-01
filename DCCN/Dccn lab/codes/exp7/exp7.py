NUL=1000
INF=999

def init(n):
    t=[[[i,None,(0 if i==j else INF)][:] for j in range(n)] for i in range(n)]
    # structure: t[src][dst] = [dst_index, next_hop_index or None, dist]
    for i in range(n):
        for j in range(n):
            t[i][j][0]=j
    return t

def inp(t):
    n=len(t)
    for i in range(n):
        print(f"\nEnter link cost from node {i+1} to others:")
        for j in range(n):
            if i==j: continue
            c=int(input(f"Cost to node {j+1} (999 if no link): "))
            if c!=INF:
                t[i][j][2]=c
                t[i][j][1]=j

def update(t):
    n=len(t)
    for _ in range(n):
        for x in range(n):
            for y in range(n):
                for via in range(n):
                    if t[x][via][2]>=INF: continue
                    d=t[x][via][2]+t[via][y][2]
                    if d < t[x][y][2]:
                        t[x][y][2]=d; t[x][y][1]=via

def print_tables(t,desc):
    print(f"\nRouting Tables {desc}:")
    n=len(t)
    for x in range(n):
        print(f"\nRouting table for node {x+1}:\nDEST\tDIST\tNEXT_HOP")
        for i in range(n):
            dist=t[x][i][2]; hop=t[x][i][1]
            if dist>=INF: print(f"{i+1}\tNO LINK\tNO HOP")
            elif hop is None: print(f"{i+1}\t{dist}\tNO HOP")
            else: print(f"{i+1}\t{dist}\t{hop+1}")

def find_route(t,src,dst):
    path=[]
    i=src-1; j=dst-1
    if t[i][j][2]>=INF:
        print("No route")
        return
    while True:
        path.append(i+1)
        if t[i][j][1]==j: break
        i=t[i][j][1]
    print(" -> ".join(map(str,path+[dst])))
    print("Shortest distance =", t[src-1][dst-1][2])

def main():
    while True:
        no=int(input("Enter the number of nodes (1–10): "))
        if 1<=no<=10: break
    t=init(no); inp(t)
    print_tables(t,"(Initial)")
    update(t)
    print_tables(t,"After Path Computation")
    while True:
        if not int(input("\nEnter 0 to exit, any other number to find shortest path: ")): break
        x,y=map(int,input("Enter the nodes (src dest): ").split())
        print(f"\nBest route from node {x} to {y} is:")
        find_route(t,x,y)

if __name__=="__main__":
    main()
