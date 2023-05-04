class Node:
    def __init__(self):
        self.pred = 0
        self.dist = 0
        self.stat = 0


class Edge:
    def __init__(self):
        self.u = 0
        self.v = 0


class Graph:
    def __init__(self):
        self.adjmat = [[0] * 10 for i in range(10)]
        self.state = [Node() for i in range(10)]
        self.tree = [Edge() for i in range(10)]
        self.wt = 0

    def allperm(self, v):
        for i in range(v):
            if self.state[i].stat == 0:
                return 0
        return 1

    def initgraph(self, v):
        for i in range(v):
            for j in range(v):
                self.adjmat[i][j] = 0

    def scangraph(self, v, e):
        for i in range(e):
            while True:
                print(i+1)
                s = int(input("enter source: "))
                d = int(input("enter destination: "))
                w = int(input("enter weight: "))
                if (s >= 1 and s <= v) and (d >= 1 and d <= v):
                    if self.adjmat[s-1][d-1] == 0 and self.adjmat[d-1][s-1] == 0:
                        self.adjmat[s-1][d-1] = w
                        self.adjmat[d-1][s-1] = w
                        break
                    else:
                        print("edge already exists")
                else:
                    print("enter correct values")

    def display(self, v, e):
        for i in range(v):
            print()
            for j in range(v):
                print(self.adjmat[i][j], end=" ")
        print()

    def span(self, v, e):
        current = 0
        count = 0
        # for all vertex
        for i in range(v):
            self.state[i].pred = 0
            self.state[i].dist = 999
            self.state[i].stat = 0

        # for starting vertex
        self.state[0].pred = 0
        self.state[0].dist = 0
        self.state[0].stat = 1

        while self.allperm(v) != 1:
            for i in range(v):
                if self.adjmat[current][i] > 0 and self.state[i].stat == 0:
                    if self.adjmat[current][i] < self.state[i].dist:
                        self.state[i].pred = current
                        self.state[i].dist = self.adjmat[current][i]
            min = 999
            for i in range(v):
                if self.state[i].stat == 0 and self.state[i].dist < min:
                    current = i
                    self.state[current].stat = 1
                    u1 = self.state[current].pred
                    v1 = current
                    self.tree[count].u = u1
                    self.tree[count].v = v1
                    count += 1
                    self.wt += self.state[i].dist
        print("Total cost :", self.wt)


if __name__ == '__main__':
    g = Graph()
    g.allperm(3)
    g.initgraph(3)
    g.scangraph(3, 3)
    g.display(3, 3)
    g.span(3, 3)

# Input and output
# 1
# enter source: 1
# enter destination: 3
# enter weight: 5
# 2
# enter source: 2
# enter destination: 3
# enter weight: 7
# 3
# enter source: 1
# enter destination: 2
# enter weight: 6

# 0 6 5
# 6 0 7
# 5 7 0
# Total cost : 11
