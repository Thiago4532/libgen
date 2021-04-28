
# Random tree generator

* Defined in header [tree.hpp](lib/tree.hpp)
* `Tree : std::vector<std::pair<int,int>>`
	* `generate_prufer(int n, Generator& gen, int index = 1)`
		* n = size of the tree.
		* Generator = User created pseudo-random number generator, `std::mt19937 gen(std::random_device{}())` is recommended.
		* Generates a random prüfer sequence and builds the tree defined by it.
	* `generate_blocks(int n, int group_size, Generator& gen, int index = 1)`
		* Since most random prüfer sequences don't generate 'dense' trees, that is trees with small diameter and nodes with large degree, this function first defines some blocks of random size between 1 and group_size and then builds a prüfer-generated tree using those blocks as nodes.
		* Can be used to generate 'dense' trees.
* `WeightedTree<typename T = int, int index = 1, typename Randomizer = randomizer<T>> : std::vector<std::pair<std::pair<int,int>, T>>`
	* `generate_prufer(int n, std::pair<T, T> const& range, Generator& gen)`
		* Generates the underlying tree using Tree::generate_prufer and sets the values of the edges of type T in the range [range.first, range.second]
	* `generate_blocks(int n, int group_size, std::pair<T, T> const& range, Generator& gen)`
		* Generates the underlying tree using Tree::generate_blocks and sets the values of the edges of type T in the range [range.first, range.second]
