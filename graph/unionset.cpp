#include <cstdio>
#include <vector>

class UnionSet
{
public:
    UnionSet(int n)
    {
        parent.resize(n, NOT_IN_SET);
        size.resize(n, 0);
    }

    bool insert(int k1, int k2)
    {
        if (same_set(k1, k2)) {
            printf("%d and %d are already in the same set\n", k1, k2);
            return false;
        }

        // Creates a new set
        if (!is_in_set(k1) && !is_in_set(k2)) {
            parent[k1] = parent[k2] = k1;
            size[k1] = 2;
            printf("Added %d and %d to a new set\n", k1, k2);
            return true;
        }

        // Adds k1 into the set
        if (!is_in_set(k1)) {
            parent[k1] = k2;
            size[find_root(k1)]++;
            printf("Added %d to the set\n", k1);
            return true;
        }

        // Adds k2 into the set
        if (!is_in_set(k2)) {
            parent[k2] = k1;
            size[find_root(k2)]++;
            printf("Added %d to the set\n", k2);
            return true;
        }

        // k1 and k2 are in different sets
        int r1 = find_root(k1);
        int r2 = find_root(k2);
        if (size[r1] > size[r2]) {
            parent[r2] = r1;
            size[r1] += size[r2];
        } else {
            parent[r1] = r2;
            size[r2] += size[r1];
        }

        printf("Merged sets\n");

        return true;
    }

    int get_size(int k)
    {
        int root = find_root(k);
        return size[root];
    }

    void print_sets()
    {
        int n = parent.size();
        int set_count = 0;
        std::vector<bool> used(n, false);
        for (int i = 0; i < n; i++) {
            if (!is_in_set(i) || used[i])
                continue;

            int curr = find_root(i);
            printf("Set %d (size: %d): %d", set_count++, size[curr], i);
            used[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!is_in_set(j) || used[j] || find_root(j) != curr) {
                    continue;
                }
                printf(" %d", j);
                used[j] = true;
            }
            printf("\n");
        }
        printf("\n");
    }

private:
    const int NOT_IN_SET = -1;
    std::vector<int> parent;
    std::vector<int> size;

    int find_root(int k)
    {
        if (!is_in_set(k))
            return NOT_IN_SET;
        return parent[k] == k ? k : parent[k] = find_root(parent[k]);
    }

    bool same_set(int k1, int k2)
    {
        int root1 = find_root(k1);
        int root2 = find_root(k2);
        return (root1 == NOT_IN_SET || root2 == NOT_IN_SET) ? false
                                                            : root1 == root2;
    }

    bool is_in_set(int k) const { return parent[k] != NOT_IN_SET; }
};

int main()
{
    UnionSet us(1000);

    for (;;) {
        printf("Enter a pair of numbers: ");
        fflush(stdout);

        int k1, k2;
        scanf("%d %d", &k1, &k2);

        us.insert(k1, k2);
        us.print_sets();
    }

    return 0;
}
