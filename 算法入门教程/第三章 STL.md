# STL

### STL简介

STL（Standard Template Library，标准模板库）是C++语言中的一个库，它提供了一系列模板化的数据结构和算法。对于ACM（Association for Computing Machinery）中的编程竞赛，STL起到了以下作用：

1. **快速编程**：STL提供了一系列预定义的数据结构（如`vector`、`set`、`map`等）和算法（如`sort`、`binary_search`等），使得参赛者可以快速地编写代码，而不需要从零开始实现这些基础功能。
2. **提高效率**：STL中的数据结构和算法都经过了优化，确保了高效的性能。使用STL可以帮助参赛者确保他们的解决方案在时间和空间上都是高效的。
3. **减少错误**：由于STL的组件都经过了广泛的测试，所以使用它们可以减少代码中的错误，提高代码的稳定性。
4. **简化代码**：STL的组件设计得很通用，可以应对各种问题。这意味着参赛者可以用更少的代码来解决问题，使得代码更加简洁和易于理解。

总的来说，STL为ACM编程竞赛提供了强大的工具，使得参赛者可以更加专注于解决实际的问题，而不是重复地实现基础的数据结构和算法。

### vector向量

`vector` 是 C++ STL 中的一个动态数组容器，它能够自动管理其大小，为用户提供了许多方便的功能。以下是关于 `vector` 的一些基本介绍：

##### 头文件

要使用 `vector`，你需要包含其头文件：
```cpp
#include <vector>
```

##### 常用功能与函数

1. **初始化**
   ```cpp
   std::vector<int> v1;           // 空的整数向量
   std::vector<int> v2(5);        // 包含5个元素的整数向量，每个元素都初始化为0
   std::vector<int> v3(5, 10);    // 包含5个元素的整数向量，每个元素都初始化为10
   ```

2. **访问元素**
   ```cpp
   v1[2] = 50;        // 使用数组索引语法
   v1.at(2) = 50;     // 使用 at() 函数
   ```

3. **添加元素**
   ```cpp
   v1.push_back(20);  // 在向量的末尾添加一个元素
   ```

4. **删除元素**
   ```cpp
   v1.pop_back();     // 删除向量的最后一个元素
   ```

5. **大小和容量**
   ```cpp
   int size = v1.size();          // 返回向量中的元素数量
   int capacity = v1.capacity();  // 返回向量当前的容量
   bool isEmpty = v1.empty();     // 检查向量是否为空
   ```

6. **清除**
   ```cpp
   v1.clear();        // 清除向量中的所有元素
   ```

7. **迭代**
   ```cpp
   for(auto it = v1.begin(); it != v1.end(); ++it) {
       // 使用迭代器遍历向量
   }
   ```

8. **查找**
   使用 `std::find` 函数可以在 `vector` 中查找元素：
   ```cpp
   #include <algorithm>
   auto it = std::find(v1.begin(), v1.end(), 20);
   if(it != v1.end()) {
       // 找到了元素
   }
   ```

9. **排序**
   使用 `std::sort` 函数可以对 `vector` 进行排序：
   ```cpp
   #include <algorithm>
   std::sort(v1.begin(), v1.end());
   ```

10. **反转**
    使用 `std::reverse` 函数可以反转 `vector`：
    
    ```cpp
    #include <algorithm>
    std::reverse(v1.begin(), v1.end());
    ```

这只是 `vector` 的一些基本功能。实际上，`vector` 提供了许多其他功能和方法，使其成为 C++ 中非常强大和灵活的数据结构。
##### 经典问题
**寻找数组中的“失踪的数字”**。
问题描述：
给定一个包含 `0, 1, 2, ..., n` 中 `n` 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

例如，给定的序列为 `3, 0, 1`，那么缺失的数字就是 `2`。

解决方案：
我们可以使用 `vector` 的特性来解决这个问题。一个简单的方法是使用数学的方法。首先计算 0 到 n 的所有数字的和，然后减去给定序列中的所有数字的和，得到的结果就是缺失的数字。

以下是使用C++和`vector`实现的解决方案：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;  // 使用高斯求和公式
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "缺失的数字是: " << missingNumber(nums) << endl;  // 输出: 2
    return 0;
}
```

这个方法的时间复杂度是 O(n)，其中 n 是数组的长度。


### pair

`pair`是STL中的一个简单的数据结构，用于存储两个元素的组合。它定义在`<utility>`头文件中。

##### 常用函数和操作：

1. **构造函数**：可以使用构造函数创建一个`pair`。
  
   ```cpp
   pair<T1, T2> p(value1, value2);
   ```
   
2. **make_pair**：这是一个辅助函数，用于创建`pair`。
   ```cpp
   auto p = make_pair(value1, value2);
   ```

3. **访问元素**：
   - `first`：访问`pair`的第一个元素。
   - `second`：访问`pair`的第二个元素。

##### 代码演示：

```cpp
#include <iostream>
#include <utility>  // 包含pair的定义

int main() {
    // 使用构造函数创建pair
    std::pair<int, std::string> p1(1, "one");

    // 使用make_pair函数创建pair
    auto p2 = std::make_pair(2, "two");

    // 访问pair的元素
    std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

    return 0;
}
```

输出：
```
p1: 1, one
p2: 2, two
```

`pair`通常与其他STL容器一起使用，例如`map`和`unordered_map`，其中每个元素都是一个键值对，存储为`pair`。
##### 经典问题

**问题描述：**找到数组中的两个数，使它们的和等于给定的目标值。

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> findTwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndexMap;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numIndexMap.find(complement) != numIndexMap.end()) {
            return make_pair(numIndexMap[complement], i);
        }
        numIndexMap[nums[i]] = i;
    }
    
    return make_pair(-1, -1);  // 如果没有找到匹配的数对
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    pair<int, int> result = findTwoSum(nums, target);
    
    if (result.first != -1 && result.second != -1) {
        cout << "找到两个数的索引: " << result.first << " 和 " << result.second << endl;
    } else {
        cout << "没有找到匹配的数对" << endl;
    }
    
    return 0;
}
```

在上面的代码中，`findTwoSum`函数接受一个整数数组和一个目标值，然后使用`std::unordered_map`来跟踪已经遍历过的数字以及它们的索引。在遍历数组的同时，它计算出与当前元素匹配的补数（`complement`），并检查是否已经存在于`numIndexMap`中。如果存在，就返回匹配的索引对，否则继续遍历数组。这个程序会找到数组中的两个数，使它们的和等于目标值，并返回它们的索引。如果没有找到匹配的数对，它会返回一个`pair`，其中两个值都为-1。

### string

`string` 是 C++ STL 中的一个非常重要的类，它提供了一系列操作字符串的功能。`string` 类定义在 `<string>` 头文件中。

以下是 `string` 中的一些常用函数及其简要描述：

1. **构造函数**：用于创建字符串。
  
   ```cpp
   std::string s1;           // 默认构造函数，创建一个空字符串
   std::string s2("hello");  // 从C风格字符串创建
   ```
   
2. **`size()` / `length()`**：返回字符串的长度。
   ```cpp
   std::string s = "hello";
   std::cout << s.size();  // 输出：5
   ```

3. **`empty()`**：检查字符串是否为空。
   ```cpp
   std::string s = "";
   if (s.empty()) {
       std::cout << "String is empty!";
   }
   ```

4. **`append()` / `+=`**：添加内容到字符串末尾。
   ```cpp
   std::string s = "hello";
   s.append(" world");
   s += "!";
   std::cout << s;  // 输出：hello world!
   ```

5. **`substr()`**：返回子字符串。
   ```cpp
   std::string s = "hello world";
   std::cout << s.substr(6, 5);  // 输出：world
   ```

6. **`find()`**：查找子字符串或字符的位置。
   ```cpp
   std::string s = "hello world";
   size_t pos = s.find("world");
   if (pos != std::string::npos) {
       std::cout << "Found at position: " << pos;
   }
   ```

7. **`replace()`**：替换子字符串。
   ```cpp
   std::string s = "hello world";
   s.replace(6, 5, "C++");
   std::cout << s;  // 输出：hello C++
   ```

8. **`erase()`**：删除子字符串。
   ```cpp
   std::string s = "hello world";
   s.erase(5, 6);
   std::cout << s;  // 输出：hello
   ```

9. **`c_str()`**：返回C风格的字符串。
   ```cpp
   std::string s = "hello";
   const char* cstr = s.c_str();
   ```

10. **`compare()`**：比较两个字符串。
    ```cpp
    std::string s1 = "hello";
    std::string s2 = "world";
    if (s1.compare(s2) == 0) {
        std::cout << "Strings are equal";
    } else {
        std::cout << "Strings are not equal";
    }
    ```

以上只是 `string` 类中常用函数的一部分。实际上，`string` 类提供了许多其他功能，可以满足各种字符串操作的需求。

##### 经典问题
**问题描述：**判断一个字符串是否是回文字符串。回文字符串是指正着读和倒着读都一样的字符串，例如"racecar"或"level"。

以下是使用C++中的`string`解决这个问题的示例代码：
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string str;
    cout << "请输入一个字符串: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "是回文字符串" << endl;
    } else {
        cout << "不是回文字符串" << endl;
    }

    return 0;
}
```

这段代码首先定义了一个`isPalindrome`函数，它使用两个指针分别指向字符串的开头和结尾，并在比较它们的字符时逐步向中间移动。如果在移动过程中发现不匹配的字符，函数会返回`false`，否则返回`true`。

然后，在`main`函数中，用户输入一个字符串，并通过调用`isPalindrome`函数来判断它是否是回文字符串。根据判断结果，程序输出相应的消息。这个问题展示了如何使用`string`来处理字符串，并且利用指针和循环来执行字符串的比较。

### queue队列

STL中的`queue`是一个容器适配器，它给予先进先出(FIFO)的特性来提供队列操作。`queue`是基于其他STL容器构建的，通常基于`deque`，但也可以基于其他容器，如`list`。

##### 头文件

要使用`queue`，你需要包含其头文件：
```c++
#include <queue>
```

##### 常用函数
1. `push(const T& x)`: 向队尾添加一个元素。
2. `pop()`: 移除队首的元素。
3. `front()`: 返回队首的元素。
4. `back()`: 返回队尾的元素。
5. `empty()`: 如果队列为空则返回true，否则返回false。
6. `size()`: 返回队列中的元素数量。

##### 代码演示
```c++
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // 添加元素到队列
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // 显示队首和队尾元素
    std::cout << "Front: " << q.front() << std::endl;  // 输出: Front: 1
    std::cout << "Back: " << q.back() << std::endl;   // 输出: Back: 4

    // 移除队首元素
    q.pop();

    // 显示队首元素
    std::cout << "Front after pop: " << q.front() << std::endl;  // 输出: Front after pop: 2

    // 检查队列是否为空以及其大小
    std::cout << "Is empty: " << q.empty() << std::endl;  // 输出: Is empty: 0
    std::cout << "Size: " << q.size() << std::endl;       // 输出: Size: 3

    return 0;
}
```

这个简单的例子展示了如何使用`queue`的基本操作。

##### 经典问题

使用队列（`queue`）来解决一个经典问题，如广度优先搜索（Breadth-First Search, BFS）是一个常见的应用。下面我们将演示如何使用C++中的`queue`来解决迷宫问题，该问题通常涉及到寻找从起点到终点的最短路径。

**问题描述**：给定一个迷宫，其中包括障碍物和空白格子，要求找到从起点到终点的最短路径。

下面是一个使用`queue`来实现BFS的C++代码示例：

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义一个点的结构体
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// 定义方向数组，表示上、下、左、右四个方向的移动
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 判断一个点是否在迷宫内且可行走
bool isValid(int x, int y, vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0;
}

// 使用BFS寻找最短路径
int bfs(vector<vector<int>>& maze, Point start, Point end) {
    queue<Point> q;
    q.push(start);
    vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), -1));
    distance[start.x][start.y] = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur.x == end.x && cur.y == end.y) {
            return distance[end.x][end.y];
        }

        for (int i = 0; i < 4; i++) {
            int newX = cur.x + dx[i];
            int newY = cur.y + dy[i];

            if (isValid(newX, newY, maze) && distance[newX][newY] == -1) {
                q.push(Point(newX, newY));
                distance[newX][newY] = distance[cur.x][cur.y] + 1;
            }
        }
    }

    return -1;  // 如果找不到路径，返回-1
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Point start(0, 0);
    Point end(4, 4);

    int shortestDistance = bfs(maze, start, end);
    if (shortestDistance != -1) {
        cout << "最短路径长度为: " << shortestDistance << endl;
    } else {
        cout << "无法找到路径" << endl;
    }

    return 0;
}
```

这个程序使用BFS算法来找到从起点到终点的最短路径，其中`queue`被用于存储待探索的点。通过这个例子，你可以看到`queue`在解决许多问题中都是非常有用的。

##### 课后习题：

**洛谷 P1440，洛谷 P2032，洛谷 P1714，洛谷 P2629，洛谷 P 2422，洛谷 P1540**

### priority_queue优先队列

`priority_queue` 是 C++ STL 中的一个容器适配器，用于处理按优先级排序的队列。它提供了常数时间的最大元素查找，对数时间的插入和删除。

##### 头文件：

```cpp
#include <queue>
```

##### 常用函数：

1. `push(element)`：将元素插入优先队列。
2. `pop()`：删除最高优先级的元素。
3. `top()`：返回最高优先级的元素。
4. `empty()`：检查优先队列是否为空。
5. `size()`：返回优先队列中的元素数量。

##### 代码演示：

```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // 插入元素
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(25);

    // 输出最高优先级的元素
    std::cout << "Top element: " << pq.top() << std::endl;  // 输出：25

    // 删除最高优先级的元素
    pq.pop();

    // 输出最高优先级的元素
    std::cout << "Top element after pop: " << pq.top() << std::endl;  // 输出：20

    // 检查队列是否为空
    if (!pq.empty()) {
        std::cout << "Queue is not empty and its size is: " << pq.size() << std::endl;  // 输出：3
    }

    return 0;
}
```

注意：默认情况下，`priority_queue` 使用 `operator<` 来确定优先级，因此最大的元素被视为最高优先级。如果你想要一个最小堆（即最小元素具有最高优先级），你可以使用如下定义：

```cpp
priority_queue<int, vector<int>, greater<int>> min_pq;
```

这样，`min_pq` 就是一个最小堆，其中最小元素具有最高优先级。

##### 经典问题
**Top K 问题**：从一个非常大的数据集中找到前K个最大或最小的元素。
以下是一个使用`priority_queue`解决Top K问题的示例代码，找到一个数组中的前K个最小元素：
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findTopK(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // 使用最小堆
    vector<int> topK;

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else if (num < minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    while (!minHeap.empty()) {
        topK.push_back(minHeap.top());
        minHeap.pop();
    }

    return topK;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    int k = 3;
    vector<int> topK = findTopK(nums, k);

    cout << "前" << k << "个最小元素是：";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```
在这个示例中，我们使用了`priority_queue`（最小堆）来维护前K个最小元素。首先，我们将前K个元素放入堆中，然后遍历剩余元素，如果某个元素比堆中最小元素小，就将堆中最小元素弹出，然后将该元素加入堆中。最终，堆中包含前K个最小元素。

### stack栈

STL中的`stack`是一个容器适配器，它提供了后进先出（LIFO）的数据结构。以下是关于`stack`的基本介绍：

##### **头文件**：

   ```cpp
   #include <stack>
   ```

##### **常用函数**：
   - `push(element)`: 将元素添加到栈的顶部。
   - `pop()`: 移除栈顶的元素。
   - `top()`: 返回栈顶的元素。
   - `empty()`: 如果栈为空则返回`true`，否则返回`false`。
   - `size()`: 返回栈中的元素数量。

##### **代码演示**：
   ```cpp
   #include <iostream>
   #include <stack>
   
   int main() {
       std::stack<int> s;
   
       // 添加元素到栈
       s.push(1);
       s.push(2);
       s.push(3);
       s.push(4);
   
       // 显示栈顶元素
       std::cout << "Top of the stack: " << s.top() << std::endl;
   
       // 移除栈顶元素
       s.pop();
   
       // 显示栈顶元素
       std::cout << "Top of the stack after pop: " << s.top() << std::endl;
   
       // 显示栈的大小
       std::cout << "Size of the stack: " << s.size() << std::endl;
   
       // 检查栈是否为空
       std::cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;
   
       return 0;
   }
   ```

在上述代码中，我们首先创建了一个整数类型的`stack`，然后向其添加了四个元素。接着，我们显示了栈顶的元素，移除了栈顶的元素，并再次显示了栈顶的元素。最后，我们显示了栈的大小并检查了栈是否为空。
##### 经典问题

一个经典问题，可以使用栈（stack）来解决，是**括号匹配问题**。这个问题涉及检查表达式中的括号是否正确匹配，包括圆括号 `()`、方括号 `[]` 和花括号 `{}`。正确的匹配意味着每个左括号都有对应的右括号，并且括号的嵌套顺序也必须正确。

以下是使用C++的`std::stack`来解决括号匹配问题的示例：

```cpp
#include <iostream>
#include <stack>
#include <string>

bool isMatching(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

bool isValidExpression(const std::string& expression) {
    std::stack<char> brackets;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (brackets.empty() || !isMatching(brackets.top(), ch)) {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}

int main() {
    std::string expression = "{[()]()}";
    if (isValidExpression(expression)) {
        std::cout << "括号匹配正确" << std::endl;
    } else {
        std::cout << "括号匹配不正确" << std::endl;
    }
    return 0;
}
```

上述代码首先定义了一个`isMatching`函数，用于检查左右括号是否匹配。然后，`isValidExpression`函数使用栈来检查给定的表达式是否包含正确匹配的括号。最后，`main`函数测试了一个示例表达式，并输出结果。如果表达式中的括号匹配正确，它将打印"括号匹配正确"，否则将打印"括号匹配不正确"。

##### 课后习题：

**洛谷 P2947，洛谷 P5788， 洛谷 P1449， 洛谷 P1739，洛谷 P1981，洛谷 P1175**

### deque双端队列

`deque`（双端队列）是STL中的一个容器，它允许我们在其前端和后端进行插入和删除操作。`deque`是动态数组的一种扩展，提供了快速的随机访问。

##### **头文件**：
```c++
#include <deque>
```

##### **常用函数**：
1. `push_front(val)`：在前端插入元素。
2. `push_back(val)`：在后端插入元素。
3. `pop_front()`：删除前端元素。
4. `pop_back()`：删除后端元素。
5. `front()`：返回前端元素。
6. `back()`：返回后端元素。
7. `begin()`、`end()`：返回迭代器到开始和结束位置。
8. `size()`：返回`deque`中的元素数量。
9. `empty()`：检查`deque`是否为空。
10. `clear()`：清除所有元素。
11. `operator[]`：随机访问元素。

##### **代码演示**：
```c++
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;

    // 插入元素
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(0);

    // 输出：0 1 2 3
    for (int i : d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 删除元素
    d.pop_back();
    d.pop_front();

    // 输出：1 2
    for (int i : d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 访问元素
    std::cout << "Front: " << d.front() << std::endl;  // 输出：Front: 1
    std::cout << "Back: " << d.back() << std::endl;    // 输出：Back: 2

    // 随机访问
    std::cout << "Element at index 1: " << d[1] << std::endl;  // 输出：Element at index 1: 2

    return 0;
}
```

这只是`deque`的一些基本功能。由于其灵活性和效率，`deque`在许多应用中都非常有用，特别是当需要在容器的前端和后端都进行操作时。

##### 经典问题

**问题描述：**

假设你正在模拟一个车辆排队系统，有多辆车等待进入一个停车场。车辆按照到达的顺序排队，并且可以从队头或队尾进入或离开停车场。你需要实现一个程序，模拟车辆的进出顺序，并且能够查询当前停车场内的车辆数量。

**解决方案：**

可以使用deque来实现这个停车场模拟系统，deque的前端和后端分别模拟停车场的入口和出口。

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> parkingLot; // 使用deque来模拟停车场
    int choice, carNumber;

    while (true) {
        cout << "请选择操作：\n1. 车辆到达\n2. 车辆离开\n3. 查询停车场内车辆数量\n4. 退出\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "请输入车辆号码： ";
                cin >> carNumber;
                parkingLot.push_back(carNumber); // 车辆到达，从队尾进入停车场
                cout << "车辆 " << carNumber << " 已进入停车场。\n";
                break;
            
            case 2:
                if (!parkingLot.empty()) {
                    carNumber = parkingLot.front(); // 车辆离开，从队头出停车场
                    parkingLot.pop_front();
                    cout << "车辆 " << carNumber << " 已离开停车场。\n";
                } else {
                    cout << "停车场已空，无车辆可离开。\n";
                }
                break;

            case 3:
                cout << "当前停车场内有 " << parkingLot.size() << " 辆车。\n";
                break;

            case 4:
                cout << "程序已退出。\n";
                return 0;
            
            default:
                cout << "无效的选项，请重新选择。\n";
        }
    }

    return 0;
}
```

这个程序使用deque来模拟车辆的进入和离开停车场，以及查询停车场内的车辆数量。用户可以选择不同的操作来模拟车辆的行为。deque的前端和后端分别用于模拟停车场的入口和出口，使得操作非常高效。

### set

`set` 是 C++ STL 中的一个关联容器，它存储唯一的元素，并且元素是有序的。`set` 是基于红黑树实现的，所以它的插入、删除和查找操作的时间复杂度都是 O(log n)。

##### **头文件**：

```cpp
#include <set>
```

##### **常用函数**：
1. `insert(val)`：插入元素。
2. `erase(val)`：删除指定的元素。
3. `find(val)`：查找指定的元素，返回一个迭代器。如果找不到，则返回 `end()`。
4. `begin()`：返回指向第一个元素的迭代器。
5. `end()`：返回指向最后一个元素之后的迭代器。
6. `size()`：返回元素的数量。
7. `empty()`：检查 `set` 是否为空。

##### **代码演示**：
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    // 插入元素
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    // 输出 set 中的元素
    for (int val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;  // 输出：10 20 30 40

    // 查找元素
    if (s.find(20) != s.end()) {
        std::cout << "20 is in the set." << std::endl;  // 输出：20 is in the set.
    }

    // 删除元素
    s.erase(20);

    // 再次查找元素
    if (s.find(20) == s.end()) {
        std::cout << "20 is not in the set." << std::endl;  // 输出：20 is not in the set.
    }

    return 0;
}
```

这只是 `set` 的基本操作，`set` 还有很多其他有用的函数，如 `lower_bound()`, `upper_bound()` 等，可以帮助你更高效地处理数据。

##### 经典问题

**问题描述：**给定一个整数数组，找出数组中是否存在重复元素。

以下是使用`std::set`解决这个问题的C++代码：

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> uniqueNums;
    
    for (int num : nums) {
        if (uniqueNums.find(num) != uniqueNums.end()) {
            // 数字已经存在于set中，说明有重复元素
            return true;
        }
        uniqueNums.insert(num);
    }
    
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 1}; // 存在重复元素1
    if (containsDuplicate(nums)) {
        cout << "数组中存在重复元素。" << endl;
    } else {
        cout << "数组中没有重复元素。" << endl;
    }
    
    return 0;
}
```

在这个例子中，我们使用了一个`std::set`来存储数组中的唯一元素。如果在遍历数组时发现一个元素已经在集合中存在，那么就说明数组中存在重复元素。否则，如果遍历完成后都没有发现重复元素，就返回`false`表示没有重复元素。

这个问题的时间复杂度是O(n)，因为我们需要遍历整个数组，并且`std::set`的插入和查找操作都是O(log n)的复杂度，总的复杂度是O(n * log n)。

### map
`std::map` 是 C++ STL 中的一个关联容器，它存储键值对，并按键进行排序。`map` 的每个键都是唯一的，与其关联一个值。以下是关于 `std::map` 的一些基本信息：

##### 头文件
```cpp
#include <map>
```

##### 常用函数

1. **插入元素** - `insert()`
2. **访问元素** - 使用 `[]` 运算符
3. **查找元素** - `find()`
4. **删除元素** - `erase()`
5. **获取大小** - `size()`
6. **检查是否为空** - `empty()`
7. **清空所有元素** - `clear()`

##### 代码演示

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap;

    // 插入元素
    ageMap.insert(std::make_pair("Alice", 25));
    ageMap.insert(std::make_pair("Bob", 30));
    ageMap["Charlie"] = 35;

    // 访问元素
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

    // 查找元素
    if (ageMap.find("Bob") != ageMap.end()) {
        std::cout << "Bob is in the map." << std::endl;
    } else {
        std::cout << "Bob is not in the map." << std::endl;
    }

    // 删除元素
    ageMap.erase("Alice");

    // 获取大小
    std::cout << "Size of the map: " << ageMap.size() << std::endl;

    // 检查是否为空
    if (ageMap.empty()) {
        std::cout << "The map is empty." << std::endl;
    } else {
        std::cout << "The map is not empty." << std::endl;
    }

    // 清空所有元素
    ageMap.clear();

    return 0;
}
```

这只是 `std::map` 的基本使用。`std::map` 还有许多其他功能和方法，如迭代器访问、`lower_bound()`、`upper_bound()` 等，可以为编程提供更多的灵活性。

##### 经典问题

**问题描述：**找到一个数组中重复次数最多的元素。

以下是一个使用`std::map`解决此问题的C++示例代码：

```cpp
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findMostFrequentElement(vector<int>& nums) {
    map<int, int> frequency;  // 使用map来统计每个元素的频率

    // 遍历数组并计数
    for (int num : nums) {
        frequency[num]++;
    }

    int mostFrequentElement = -1;
    int maxFrequency = 0;

    // 遍历map以找到重复次数最多的元素
    for (const auto& entry : frequency) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            mostFrequentElement = entry.first;
        }
    }

    return mostFrequentElement;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int result = findMostFrequentElement(nums);

    cout << "重复次数最多的元素是: " << result << endl;
    return 0;
}
```

在上面的代码中，我们使用`std::map`来统计每个元素的频率，然后遍历map以找到重复次数最多的元素。这是一个简单的示例，展示了如何使用`std::map`解决一个经典问题：找到数组中的众数（重复次数最多的元素）。

### unordered_map

`unordered_map` 是 C++ STL 中的一个容器，它存储键值对，但不保证元素的有序性。它基于哈希表实现，因此平均情况下对键的访问、插入和删除操作的时间复杂度都是 O(1)。

##### 头文件
要使用 `unordered_map`，你需要包含以下头文件：
```cpp
#include <unordered_map>
```

##### 常用函数

1. **插入**：`insert()`
2. **访问**：使用 `[]` 运算符
3. **查找**：`find()`
4. **删除**：`erase()`
5. **大小**：`size()`
6. **检查是否为空**：`empty()`
7. **清空**：`clear()`

##### 代码演示

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    // 插入
    umap["apple"] = 10;
    umap["banana"] = 20;
    umap["cherry"] = 30;

    // 访问
    std::cout << "apple: " << umap["apple"] << std::endl;

    // 查找
    if (umap.find("banana") != umap.end()) {
        std::cout << "banana found!" << std::endl;
    }

    // 删除
    umap.erase("apple");

    // 遍历
    for (auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 大小
    std::cout << "Size: " << umap.size() << std::endl;

    // 清空
    umap.clear();
    std::cout << "Size after clear: " << umap.size() << std::endl;

    return 0;
}
```

这个示例展示了如何使用 `unordered_map` 的基本操作，包括插入、访问、查找、删除和遍历。

##### 经典问题

**问题描述：**统计一组数字中每个数字出现的次数。

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 1, 2, 2, 3, 3, 3};

    // 创建一个无序映射，用于统计数字出现的次数
    unordered_map<int, int> frequency;

    // 遍历数字，更新频率计数
    for (int num : numbers) {
        frequency[num]++;
    }

    // 打印每个数字和其出现次数
    for (auto it = frequency.begin(); it != frequency.end(); ++it) {
        cout << "数字 " << it->first << " 出现了 " << it->second << " 次" << endl;
    }

    return 0;
}
```

上述代码创建了一个`unordered_map`容器`frequency`，用于存储每个数字出现的次数。然后，它遍历给定的数字数组，对每个数字更新其在`frequency`中的计数。最后，它打印了每个数字和其出现次数。

这是`unordered_map`的一个常见用例，它可以高效地实现键值对的存储和查找，适用于许多问题，如计数、查找和数据统计等。

### min,max
在C++的STL中，`min`和`max`函数都定义在`<algorithm>`头文件中。

1. **min函数**：
   - `min(a, b)`：返回`a`和`b`中的最小值。
   - `min({a, b, c, ...})`：返回列表中的最小值（C++11起）。
   - `min(a, b, comp)`：使用比较函数`comp`返回`a`和`b`中的最小值。

2. **max函数**：
   - `max(a, b)`：返回`a`和`b`中的最大值。
   - `max({a, b, c, ...})`：返回列表中的最大值（C++11起）。
   - `max(a, b, comp)`：使用比较函数`comp`返回`a`和`b`中的最大值。

以下是代码示例：

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int a = 5, b = 10;

    // 使用min和max函数
    std::cout << "min: " << std::min(a, b) << std::endl;
    std::cout << "max: " << std::max(a, b) << std::endl;

    // 使用自定义比较函数
    auto comp = [](int x, int y) { return x > y; }; // 返回较大的数
    std::cout << "min with comp: " << std::min(a, b, comp) << std::endl; // 实际上返回较大的数
    std::cout << "max with comp: " << std::max(a, b, comp) << std::endl; // 实际上返回较小的数

    // 使用初始化列表（C++11起）
    std::cout << "min from list: " << std::min({a, b, 3, 7, 2}) << std::endl;
    std::cout << "max from list: " << std::max({a, b, 3, 7, 2}) << std::endl;

    return 0;
}
```

这些函数都非常简单易用，可以帮助你快速找到最小值或最大值，而不需要写额外的比较逻辑。

### sort
STL中的`sort`函数是一个非常强大的排序算法，它包含在`<algorithm>`头文件中。

##### 常用函数：

1. **sort(begin, end)**：对序列[begin, end)进行排序。
2. **sort(begin, end, comparator)**：使用自定义的比较函数`comparator`对序列[begin, end)进行排序。

##### 代码演示：

1. **基本排序**：
```c++
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::sort(v.begin(), v.end());
    for (int i : v) {
        std::cout << i << " ";
    }
    return 0;
}
```

输出：
```
1 1 2 3 3 4 5 5 5 6 9 
```

2. **使用自定义比较函数**：
```c++
#include <iostream>
#include <algorithm>
#include <vector>

bool compare(int a, int b) {
    return a > b;  // 降序排序
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::sort(v.begin(), v.end(), compare);
    for (int i : v) {
        std::cout << i << " ";
    }
    return 0;
}
```

输出：
```
9 6 5 5 5 4 3 3 2 1 1 
```

这些示例展示了如何使用STL中的`sort`函数进行基本排序和使用自定义比较函数进行排序。

##### 课后习题：

**洛谷 P1093**

### __gcd

在C++的STL中，`__gcd`是一个用于计算两个整数的最大公约数（Greatest Common Divisor）的函数。它位于`<algorithm>`头文件中。

##### 常用函数：
- `__gcd(a, b)`: 返回`a`和`b`的最大公约数。

##### 代码演示：
```cpp
#include <iostream>
#include <algorithm>  // 包含__gcd函数的头文件

int main() {
    int a = 56, b = 98;
    int result = __gcd(a, b);
    std::cout << "The GCD of " << a << " and " << b << " is: " << result << std::endl;
    return 0;
}
```

在上面的代码中，我们使用`__gcd`函数计算了56和98的最大公约数，并输出了结果。
### swap
`swap` 是 C++ STL 中的一个常用函数，用于交换两个对象的值。它是定义在 `<algorithm>` 头文件中的。

##### 常用函数：

1. **swap(a, b)**：交换 `a` 和 `b` 的值。

##### 代码演示：

```cpp
#include <iostream>
#include <algorithm>  // 包含swap函数

int main() {
    int a = 5, b = 10;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    std::swap(a, b);  // 使用swap交换a和b的值

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
```

输出：
```
Before swap: a = 5, b = 10
After swap: a = 10, b = 5
```

除了基本数据类型，`swap` 还可以用于自定义数据类型（如类和结构体）和 STL 容器（如 `vector`、`list`、`set` 等）。只要这些类型提供了移动构造函数和移动赋值操作符，或者它们的复制构造函数和复制赋值操作符是可用的，`swap` 就可以用于它们。

### lower_bound()和upper_bound()

`lower_bound()` 和 `upper_bound()` 是STL中的两个非常有用的函数，用于在已排序的序列中进行二分查找。它们都定义在 `<algorithm>` 头文件中。

1. **lower_bound()**:
   - 返回指向在已排序序列中首次出现不小于给定值的元素的迭代器。
   - 如果所有元素都小于给定值，则返回序列的尾部迭代器。

2. **upper_bound()**:
   - 返回指向在已排序序列中首次出现大于给定值的元素的迭代器。
   - 如果所有元素都不大于给定值，则返回序列的尾部迭代器。

以下是一个使用这两个函数的C++代码示例：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 4, 4, 5, 6};

    // 使用 lower_bound() 查找第一个不小于4的元素
    std::vector<int>::iterator low = std::lower_bound(v.begin(), v.end(), 4);
    std::cout << "lower_bound for 4 at position " << (low - v.begin()) << '\n';

    // 使用 upper_bound() 查找第一个大于4的元素
    std::vector<int>::iterator up = std::upper_bound(v.begin(), v.end(), 4);
    std::cout << "upper_bound for 4 at position " << (up - v.begin()) << '\n';

    return 0;
}
```

输出：
```
lower_bound for 4 at position 2
upper_bound for 4 at position 4
```

在这个示例中，`lower_bound()` 返回第一个不小于4的元素的位置，即第一个4的位置，而 `upper_bound()` 返回第一个大于4的元素的位置，即5的位置。

##### 经典问题

**问题描述：**查找某个元素的出现次数。

以下是一个使用 `lower_bound()` 和 `upper_bound()` 解决查找元素出现次数的经典问题的示例：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    // 使用 lower_bound 找到目标元素的第一个出现位置
    auto lower = lower_bound(nums.begin(), nums.end(), target);
au
    // 使用 upper_bound 找到目标元素的下一个位置
    auto upper = upper_bound(nums.begin(), nums.end(), target);

    // 计算目标元素的出现次数
    int count = upper - lower;

    cout << "元素 " << target << " 出现了 " << count << " 次" << endl;

    return 0;
}
```

在这个示例中，我们首先使用 `lower_bound()` 找到目标元素2的第一个出现位置，然后使用 `upper_bound()` 找到下一个位置。最后，我们计算这两个位置之间的元素个数，这就是目标元素的出现次数。这个程序会输出元素2出现了3次，因为它在数组中出现了3次。这种方法也适用于其他有序容器，如数组或链表。

##### 课后习题：

**洛谷 P1052，洛谷 P2097，洛谷 P2652**

### max_element，min_element和distance

当然可以，让我们逐一介绍这些函数：

##### **头文件**：
   `max_element`, `min_element` 和 `distance` 都位于 `<algorithm>` 和 `<iterator>` 头文件中。

##### **函数介绍**：
   - **max_element**: 返回指向范围内最大元素的迭代器。
   - **min_element**: 返回指向范围内最小元素的迭代器。
   - **distance**: 返回两个迭代器之间的距离。

##### **代码演示**：
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 使用max_element找到最大元素的迭代器
    auto max_it = std::max_element(v.begin(), v.end());
    std::cout << "Max element: " << *max_it << std::endl;

    // 使用min_element找到最小元素的迭代器
    auto min_it = std::min_element(v.begin(), v.end());
    std::cout << "Min element: " << *min_it << std::endl;

    // 使用distance计算两个迭代器之间的距离
    int dist = std::distance(v.begin(), max_it);
    std::cout << "Distance from beginning to max element: " << dist << std::endl;

    return 0;
}
```

在上述代码中，我们首先定义了一个整数向量`v`。然后，我们使用`max_element`和`min_element`函数找到向量中的最大和最小元素，并使用`distance`函数计算从向量的开始到最大元素的距离。

##### 经典问题

**问题描述：**找到数组中的最大元素和最小元素，并计算它们之间的距离。你可以使用C++标准库中的`max_element`、`min_element`和`distance`函数来解决这个问题。

以下是一个示例，演示如何使用这些函数来解决问题：

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // 包括max_element、min_element和distance函数
using namespace std;

int main() {
    // 创建一个整数向量
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 使用max_element找到最大元素的迭代器
    auto maxIter = max_element(numbers.begin(), numbers.end());

    // 使用min_element找到最小元素的迭代器
    auto minIter = min_element(numbers.begin(), numbers.end());

    // 使用distance计算最大元素和最小元素之间的距离
    int dis = distance(minIter, maxIter);

    // 输出最大元素、最小元素和它们之间的距离
    cout << "最大元素: " << *maxIter << endl;
    cout << "最小元素: " << *minIter << endl;
    cout << "它们之间的距离: " << dis << endl;

    return 0;
}
```

在这个示例中，我们创建了一个整数向量`numbers`，然后使用`max_element`和`min_element`找到最大元素和最小元素的迭代器。最后，我们使用`distance`函数计算这两个迭代器之间的距离，并输出结果。这个程序将输出最大元素、最小元素和它们之间的距离。