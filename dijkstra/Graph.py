from queue import PriorityQueue
import multiprocessing as mp


class Graph:
    def __init__(self):
        self.vertexes = []
        self.visited = []
        self.edges = [[]]

    def addVertex(self, v):
        self.vertexes.append(v)
        newRow = []
        self.edges.append(newRow)
        for i in range(len(self.vertexes)):
            self.edges[i].append(0)

        for i in range(len(self.vertexes)):
            newRow.append(0)


    def addEdge(self, x, y, weight):
            self.edges[x][y] = weight
            self.edges[y][x] = weight


    def findBestPathSequential(self, start):
        path = {v: float('inf') for v in self.vertexes}

        path[start] = 0

        priorityQueue = PriorityQueue()
        priorityQueue.put((0, start))
        while not priorityQueue.empty():
            (dist, current_vertex) = priorityQueue.get()
            self.visited.append(current_vertex)

            for neighbor in self.vertexes:
                if self.edges[current_vertex][neighbor] == 0:
                    continue
                distance = self.edges[current_vertex][neighbor]
                if neighbor not in self.visited:
                    old_cost = path[neighbor]
                    new_cost = path[current_vertex] + distance
                    if new_cost < old_cost:
                        priorityQueue.put((new_cost, neighbor))
                        path[neighbor] = new_cost
        return path


    def findBestPathParallel(self, start):
        pool = mp.Pool(mp.cpu_count())
        path = mp.Manager().dict()
        for v in self.vertexes:
            path[v] = float('inf')
        # path = {v: float('inf') for v in self.vertexs}
        path[start] = 0

        priority_queue = PriorityQueue()
        priority_queue.put((0, start))

        vertexes_to_updated = []
        while not priority_queue.empty():
            (dist, current_vertex) = priority_queue.get()
            self.visited.append(current_vertex)
            vertexes_to_updated.clear()

            for neighbor in self.vertexes:
                if self.edges[current_vertex][neighbor] == 0:
                    continue
                if neighbor in self.visited:
                    continue
                vertexes_to_updated.append(pool.apply_async(self.updateLabel, (path, current_vertex, neighbor)))
            for pair in vertexes_to_updated:
                if pair.get()[0] != 0:
                    priority_queue.put(pair.get())
        #
        pool.close()
        pool.join()


        return path

    def updateLabel(self, path, current_vertex, neighbor ):

        distance = self.edges[current_vertex][neighbor]
        old_cost = path[neighbor]
        new_cost = path[current_vertex] + distance
        if new_cost < old_cost:
            path[neighbor] = new_cost #update label
            return new_cost, neighbor
        return 0, neighbor


g = Graph()

g.addVertex(0)
g.addVertex(1)
g.addVertex(2)
g.addVertex(3)
g.addVertex(4)
g.addEdge(0, 1, 5)
g.addEdge(0, 4, 3)
g.addEdge(1, 2, 1)
g.addEdge(1, 3, 10)
g.addEdge(1, 4, 8)
g.addEdge(2, 3, 7)
g.addEdge(3, 4, 1)

# print(g.findBestPathSequential(0))

if __name__ == '__main__':
    print(g.findBestPathParallel(0))
