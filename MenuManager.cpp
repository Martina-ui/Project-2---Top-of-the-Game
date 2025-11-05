#include "MenuManager.h"
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
// #include "mergeSort.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace bridges;

vector<Games> MenuManager::get_games_data() {
    char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); 
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");

	Bridges bridges(1, mySecretUser, mySecretAPI);

	DataSource ds (&bridges);
	vector<Game> game_list = ds.getGameData();
    vector<Games> games_info;
	for (const auto& g : game_list) {
		Games game(g.getTitle(), g.getPlatformType(), g.getGameGenre(), static_cast<float>(g.getRating()));
		game.set_title(g.getTitle());
		game.set_platform_type(g.getPlatformType());
		game.set_genres(g.getGameGenre());
		game.set_rating(static_cast<float>(g.getRating()));
		games_info.push_back(game);
	}
	return games_info; 
}

//merge sort functions from mergeSort.h moved here
void merge(vector<Games>& data, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<Games> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i].get_rating() >= R[j].get_rating()) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<Games>& data, int left, int right){

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
    cout << endl;

}

void MenuManager::get_top_N_games_mergeSort(int n) {
	auto start = chrono::high_resolution_clock::now();
	vector<Games> games = get_games_data();
	mergeSort(games, 0, games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


	for (int i = 0; i < n; i++) {
        cout << "Game " << i+1 << endl;
	    cout << "\tTitle: " << games[i].get_title() << endl
		<< "\tPlatform Type: " << games[i].get_platform_type() << endl
		<< "\tRating: " << games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < games[i].get_genre().size(); j++){
           cout << games[i].get_genre()[j] << " " ;
         };
         cout << endl << endl;

	}
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    cout << endl << endl << endl;
}


void MenuManager::get_top_N_games_by_genre_mergeSort(const string& genre, int n) {
	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		vector<string> gen = games[i].get_genre();
		for (int j = 0; j < gen.size(); j++) {
			if (gen[j] == genre) {
				updated_games.push_back(games[i]);
			}
		}
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(updated_games, 0, updated_games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
                int temp = i+1;
        cout << "Game " << temp << endl;
	    cout << "\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };

cout << endl;
	}
     cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    cout << endl << endl << endl;
}

//merge sort
void MenuManager::get_top_N_games_by_platform_mergeSort(const string& platform, int n) {

	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		if(platform == games[i].get_platform_type()) {
			updated_games.push_back(games[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(updated_games, 0, updated_games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
         int temp = i+1;
        cout << "Game " << temp << endl;
	    cout << "\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };
cout << endl;

	}
	 cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    cout << endl << endl << endl;
}

void MenuManager::get_top_N_games_by_rank_mergeSort(const float& rank, int n){

	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		if(rank == games[i].get_rating()) {
			updated_games.push_back(games[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(updated_games, 0, updated_games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	for (int i = 0; i < n; i++) {
         int temp = i+1;
        cout << "Game " << temp << endl;
	    cout << "\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };
    cout << endl;

	}
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    cout << endl << endl << endl;
}



//heap methods from HeapSort.h moved here
static bool mm_isBetter(const Games &a, const Games &b) {
    return a.get_rating() > b.get_rating();
}

void MenuManager::heapifyUp(int index) {
    int i = index;
    while (i > 0) {
        int p = parent(i);
        if (!mm_isBetter(heap[p], heap[i])) {
            std::swap(heap[p], heap[i]);
            i = p;
        } else {
            break;
        }
    }
}

void MenuManager::heapifyDown(int index) {
    int i = index;
    while (true) {
        int left = leftChild(i);
        int right = rightChild(i);
        int best = i;

        if (left < (int)heap.size() && mm_isBetter(heap[left], heap[best])) {
            best = left;
        }
        if (right < (int)heap.size() && mm_isBetter(heap[right], heap[best])) {
            best = right;
        }

        if (best == i) {
            break;
        }

        std::swap(heap[i], heap[best]);
        i = best;
    }
}

void MenuManager::HeapSort(const vector<Games> &items) {
    heap = items;
    for (int i = (int)heap.size() / 2; i >= 0; --i) {
        heapifyDown(i);
    }
}

void MenuManager::insert(const Games &g) {
    heap.push_back(g);
    heapifyUp((int)heap.size() - 1);
}

bool MenuManager::empty() const {
    return heap.empty();
}

int MenuManager::size() const {
    return (int)heap.size();
}

Games MenuManager::extractMax() {
    if (heap.empty()) {
        return Games("", "", vector<string>{}, 0.0f);
    }

    Games top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return top;
}

void MenuManager::printHeapTopNOnDataset(const vector<Games>& gamesdata, int N) {
    vector<Games> topN = getTopN_Heap(gamesdata, N);

    //cout << "\n===== Top " << N << " Games by Rating (Heap) =====\n";
    // for (const auto& g : topN) {
    //     printGame(g);
    // }
    for (int i = 0; i < N; i++) {
        cout << "Game " << i+1 << endl;
	    cout << "\tTitle: " << gamesdata[i].get_title() << endl
		<< "\tPlatform Type: " << gamesdata[i].get_platform_type() << endl
		<< "\tRating: " << gamesdata[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < gamesdata[i].get_genre().size(); j++){
           cout << gamesdata[i].get_genre()[j] << " " ;
         };
         cout << endl << endl;

	}
    //std::cout << "=============================================\n";
}

vector<Games> MenuManager::getTopN_Heap(const vector<Games> &allGames, int N) {
    auto start = chrono::high_resolution_clock::now();

    HeapSort(allGames);

    vector<Games> result;
    result.reserve(N);

    for (int i = 0; i < N && !empty(); i++) {
        Games g = extractMax();
        result.push_back(g);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    size_t numGames = allGames.size();
    size_t bytesPerGame = sizeof(Games);
    size_t totalBytes = numGames * bytesPerGame;

    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mHeap Sort" << "\e[0;37m : " << duration << " microseconds" << endl;
    cout << endl << endl << endl;

    return result;
}

// void MenuManager::printGame(const Games &g) {
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