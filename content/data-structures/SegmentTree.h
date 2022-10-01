/**
 * Author: Amit Kumar
 * Date: 2022-09-30
 * License: CC0
 * Source: Self
 * Description: Zero indexed segment tree
 * Time: O(\log N)
 */
class Node
{public:
int value;
Node() { value = INT_MAX; }; // Identity
explicit Node(int v) { value = v; }
static Node mergeSegNodes(const Node &a, const Node &b)
{Node res;
res.value = min(a.value, b.value);
return res;}
};

template <typename segNode>
class segTree
{int size;
vector<segNode> Seg;
void build(int node, int start, int end, const vector<segNode> &Base) // Recursively Builds the tree
{if (start == end)
{Seg[node] = Base[start];
return;}
int mid = (start + end) >> 1;
build(node + 1, start, mid, Base);
build(node + 2 * (mid - start + 1), mid + 1, end, Base);
Seg[node] = segNode::mergeSegNodes(Seg[node + 1], Seg[node + 2 * (mid - start + 1)]);
}

segNode rQuery(int node, int start, int end, int qstart, int qend) const // Range Query
{if (qend < start || qstart > end || start > end)
return segNode();
if (qstart <= start && end <= qend)
return Seg[node];
int mid = (start + end) >> 1;
segNode l, r;
if (qstart <= mid)
l = rQuery(node + 1, start, mid, qstart, qend);
if (qend >= mid + 1)
r = rQuery(node + 2 * (mid - start + 1), mid + 1, end, qstart, qend);
return segNode::mergeSegNodes(l, r);
}

void pUpdate(int node, int start, int end, int pos, segNode val, int type)
{if (start == end)
{Seg[node] = type ? segNode::mergeSegNodes(Seg[node], val) : val;
return;}
int mid = (start + end) >> 1;
if (pos <= mid)
pUpdate(node + 1, start, mid, pos, val, type);
else
pUpdate(node + 2 * (mid - start + 1), mid + 1, end, pos, val, type);
Seg[node] = segNode::mergeSegNodes(Seg[node + 1], Seg[node + 2 * (mid - start + 1)]);
}

public:
segTree() : segTree(0){};
explicit segTree(int n) : size(n), Seg(n << 1){};
explicit segTree(const vector<segNode> &Base) : size(Base.size())
{Seg = vector<segNode>(size << 1);
build(1, 0, size - 1, Base);}

segNode get(int pos) const
{assert(pos >= 0 && pos < size);
return rQuery(1, 0, size - 1, pos, pos);}

segNode get(int left, int right) const
{assert(left <= right && left >= 0 && right < size);
return rQuery(1, 0, size - 1, left, right);}

void update(int pos, segNode val) // Updates according to merge
{assert(pos >= 0 && pos < size);
pUpdate(1, 0, size - 1, pos, val, 1);}

void set(int pos, segNode val) // Force sets value of node
{assert(pos >= 0 && pos < size);
pUpdate(1, 0, size - 1, pos, val, 0);}
};