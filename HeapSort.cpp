// #include "data_src/Game.h"   //Bridges Game class (from Martina)
// #include "Games.h"           //local Games class
// #include <vector>
// #include <string>
// #include <iostream>
// using bridges::dataset::Game;


// using namespace std;

// static bool isBetter(const Games &a, const Games &b) {
//     return a.get_rating() > b.get_rating();
// }

// class MaxHeap {
// private:
//     vector<Games> heap;

//     int leftChild(int i) const  { return 2 * i + 1; }
//     int rightChild(int i) const { return 2 * i + 2; }
//     int parent(int i) const     { return (i - 1) / 2; }

//     void heapifyUp(int index) {
//         int i = index;
//         while (i > 0) {
//             int p = parent(i);
//             if (!isBetter(heap[p], heap[i])) {
//                 std::swap(heap[p], heap[i]);
//                 i = p;
//             } else {
//                 break;
//             }
//         }
//     }

//     void heapifyDown(int index) {
//         int i = index;
//         while (true) {
//             int left = leftChild(i);
//             int right = rightChild(i);
//             int best = i;

//             if (left < (int)heap.size() && isBetter(heap[left], heap[best])) {
//                 best = left;
//             }
//             if (right < (int)heap.size() && isBetter(heap[right], heap[best])) {
//                 best = right;
//             }

//             if (best == i) {
//                 break;
//             }

//             std::swap(heap[i], heap[best]);
//             i = best;
//         }
//     }

// public:
//     MaxHeap() {}

//     MaxHeap(const vector<Games> &items) {
//         heap = items;
//         for (int i = (int)heap.size() / 2; i >= 0; --i) {
//             heapifyDown(i);
//         }
//     }

//     void insert(const Games &g) {
//         heap.push_back(g);
//         heapifyUp((int)heap.size() - 1);
//     }

//     bool empty() const {
//         return heap.empty();
//     }

//     int size() const {
//         return (int)heap.size();
//     }

//     Games extractMax() {
//         if (heap.empty()) {
//             return Games("", "", vector<string>{}, 0.0f);
//         }

//         Games top = heap[0];
//         heap[0] = heap.back();
//         heap.pop_back();
//         if (!heap.empty()) {
//             heapifyDown(0);
//         }
//         return top;
//     }
// };

// vector<Games> getTopN_Heap(const vector<Games> &allGames, int N) {
//     auto startBuild = std::chrono::high_resolution_clock::now();
//     MaxHeap heap(allGames); 
//     auto endBuild = std::chrono::high_resolution_clock::now();

//     auto startExtract = std::chrono::high_resolution_clock::now();
//     vector<Games> result;
//     result.reserve(N);

//     for (int i = 0; i < N && !heap.empty(); i++) {
//         Games g = heap.extractMax(); 
//         result.push_back(g);
//     }

//     auto endExtract = std::chrono::high_resolution_clock::now();

//     auto buildMicros = std::chrono::duration_cast<std::chrono::microseconds>(endBuild - startBuild).count();
//     auto extractMicros = std::chrono::duration_cast<std::chrono::microseconds>(endExtract - startExtract).count();

//     size_t numGames = allGames.size();
//     size_t bytesPerGame = sizeof(Games);
//     size_t totalBytes = numGames * bytesPerGame;

//     std::cout << "[Heap] Built heap with " << numGames << " games in "
//               << buildMicros << " microseconds.\n";

//     std::cout << "[Heap] Extracted top " << result.size() << " in "
//               << extractMicros << " microseconds.\n";

//     std::cout << "[Heap] Approx memory for heap array: "
//               << totalBytes << " bytes ("
//               << bytesPerGame << " bytes * "
//               << numGames << " items)\n";

//     return result;
// }

// void printGame(const Games &g) {
//     cout << "Title: " << g.get_title()
//          << " | Platform: " << g.get_platform_type()
//          << " | Rating: " << g.get_rating()
//          << " | Genres: ";

//     vector<string> gs = g.get_genre();
//     for (size_t i = 0; i < gs.size(); i++) {
//         cout << gs[i];
//         if (i + 1 < gs.size()) cout << ", ";
//     }
//     cout << "\n";
// }

// vector<Games> convertBridgesToLocal(const vector<Game>& bridgeList) {
//     vector<Games> result;
//     result.reserve(bridgeList.size());

//     for (const auto& g : bridgeList) {
//         // pull info from Bridges' Game
//         string title        = g.getTitle();
//         string platform     = g.getPlatformType();
//         vector<string> genres = g.getGameGenre();
//         float rating        = g.getRating();

//         // build our local Games object
//         Games local(title, platform, genres, rating);
//         result.push_back(local);
//     }

//     return result;
// }

// //This is what main() or MenuManager will call.
// void runHeapTopNOnDataset(const vector<Game>& bridgeList, int N) {
//     vector<Games> localList = convertBridgesToLocal(bridgeList);

//     vector<Games> topN = getTopN_Heap(localList, N);

//     std::cout << "\n===== Top " << N << " Games by Rating (Heap) =====\n";
//     for (const auto& g : topN) {
//         printGame(g);
//     }

    
//     std::cout << "=============================================\n";
// }
