# Writers
    Пакет, отвечающий за вывод графа(ContigGraph) в dot формате 
     определенным способом. 
     
## Writer
     Интерфейс для классов, которые выводят граф. 
Внутри себя имеет:
* ContigGraph* graph - граф, который предстоит вывести. 
* Searcher searcher - класс для обхода графа.
* DotWriter dotWriter - для примитивного вывода графы в dot фрмате. 

* void write(); - функция для вывода графа. 

## WriteAlongPath
    Выводит только ребра и вершины, которые находятся в какой-то
    окрестности от ребер из определенной библиотеки. Предположительно 
    рефересной, то есть ребра образуют что-то похожее на путь. 
 
* std::string fileName - имя файла, в который выводить граф. 
* int libId - номер библиотеки, в окрестности которой будет происходить вывод. 
* int dist - растояние до пути, на котором выводить ребра и вершины.  
* int minSize - минимальный размер компоненты для вывода. 

## WriteBigComponent
    Разделяет граф по компонентам связности и выводит только 
    большие компоненты, каждый в свой файл. 
    
* minSize - минимальный размер компоненты.
    
## WriteFullGraph
    Выводит полный граф.
    
## WriteLocal
    Выводит ребра и вершины только в какой-то окрестности вершины. 
   
* int v Вершина в области которой происходит вывод
* int dist размер окрестности. Максимальное расстояние, которое может 
иметь вершина, что бы быть выведенной. 
* std::string fileName имя файлв для вывода графа.

## Searcher
    Отвечает за обход графа.
    
* ContigGraph* graph граф, который будут обходить.
* std::vector<int> findVertInLocalArea(int v, int dist) - находит
все вершины на расстоние меньше dist от вершины v.
* int findComponent(int *col) - возвращает количество компонент, 
 изменяет массив col так, что бы col[v] = номеру компоненты, в 
 котором лежит вершина v.
 
 ## DotWriter
     Выводит граф в dot формате, предварительно разбив его 
     на небольшие куски, которые можно вывести. 
     
 * ContigGraph* graph - граф, который предстоит вывести.
 * GraphSplitter graphSplitter - необходим, для разделения графа 
 на маленькие кусочки, которые будет удобно отрисовывать. 
 * void writeVertexSet(std::vector<int> vert, std::string fileName) -
 выводит данное множество вершин, предварительно разбивая их 
 на части и вводит в файл префексы имен которых совпадают 
 с fileName.
 
 ## GraphSplitter
     Разделяет граф на части небольших размеров. 
     Гарантируется, что каждая вершина и каждое 
     ребро будет находится в какой-то из частей. 
     
* int maxEdge = 15 - максимальное количество ребер в одной части
* int maxVert = 10 - максимальное количество вершин в одно части
* std::vector< std::vector<int> > split(ContigGraph* graph, std::vector<int> vert)
- разбить граф graph на части, при этом все вершины, кроме vert стоит игонрировать.
 возвращает массив частей, для каждой части записаны вершины, которые в нее входят. 