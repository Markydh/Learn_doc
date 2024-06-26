# 博弈算法

## 1. BashGame

```
每次取1∼m颗，那么我们就可以得到，如果n%(m+1)=0，即为先手必败状态，否则为先手必胜状态。而这个游戏就是著名的巴什博弈（Bash Game)
```

## 2. Nim Game

```
1.定义： 有任意堆物品，每堆物品的个数也任意，双方轮流取物品，每次只能从一堆中取至少一个物品，取到最后一件物品的人获胜。

2.结论： 把每堆物品数全部异或起来，若值为0，则先手必败，否则先手必胜。

3.证明： 我们也是不严格证明，我们将每堆物品数异或起来为0这个状态称为必败态，顾名思义，这个状态下，谁取谁必败。因为当这个状态时，经过两人轮流取物，后者始终可以维持这个必败态，即A取完后，B一定可以取一个数，使得取完后每堆物品数异或起来仍为0。这样一直到最后一轮，B取完一定会使每堆数都为0，此时同样也是必败态（异或起来为0），这时B获胜，A面对所有堆都为0这个状态取，直接失败。
所以当每堆物品数全部异或起来，若值为0，此时已是必败态，先手必败；若值不为0，则先手一定会取一个数使得每堆数异或起来为0，达到必败态，从而后手必败。
注： 博弈时，每个人都会走当前最优策略，所以每个人都会尽量给对方创造必败态，给自己创造必胜态。
```

## 3. Moore’s Nimk

```
n堆石子，每次从不超过k堆中取任意多个石子，最后不能取的人失败。

这是一个nim游戏的变形。

结论为：把n堆石子的石子数用二进制表示，统计每个二进制位上1的个数，若每一位上1的个数mod(k+1)全部为0，则必败，否则必胜。
```

## 4. 阶梯Nim

```
问题：有n堆石子，每堆石子的数量为x{1},2},...,x{n}，A,B轮流操作，每次可以选第k堆中的任意多个石子放到第k−1堆中，第1堆中的石子可以放到第0堆中，最后无法操作的人为输。问A先手是否有必胜策略。

假如我们是先手，我们就按照这个方法将多余的石子从奇数堆移动到偶数堆里面。

此后如果对手移动的是奇数堆，我们就继续移动奇数堆使得SG值重新变为00；如果对手移动的是偶数堆，我们就将他移动到奇数堆中的石子继续往下移。

这样经过多次操作我们总能使奇数堆保持必胜状态，最后我们总可以在对手之后将石子从奇数堆移动到偶数堆，最后移动到第0堆，这样对手就不能移动了。

所以通过整个过程我们可以发现，偶数堆中的石子不会影响整个游戏的结果，只有奇数堆中的石子会影响游戏结果。

结论：先手必败当且仅当奇数堆中的石子数异或和为0。
```



## 5. Wythoff Game

```
适用的游戏情况
首先有两堆石子，博弈双方每次可以取一堆石子中的任意个，不能不取，或者取两堆石子中的相同个。先取完者赢。
结论：
必胜状态必有一个后继状态是必败状态。
必败状态后继状态不可能是另一个必败状态。
必败状态通项公式：设当前状态为 (a,b)(a<b)，则当 a=⌊(sqrt(5)+1)/2⌋×(b−a) 时该状态为必败状态。
```

## 6. 斐波那契博弈

```
1.定义： 有一堆物品，共n个，两人轮流取物，先手可取任意件，但不能不取，也不能把物品取完，之后每次取的物品数不能超过上一次的两倍，且至少为1件，取走最后一件物品的人获胜。

2.结论： 当且仅当n不是斐波那契数时，先手胜。
```

