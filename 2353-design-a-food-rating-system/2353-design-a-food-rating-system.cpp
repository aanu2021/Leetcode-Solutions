class FoodRatings {
public:
    
    unordered_map<string,int>food_rating;
    unordered_map<string,string>food_cuisine;
    unordered_map<string,set<pair<int,string>>>cuisine_rating_food;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        food_rating.clear();
        food_cuisine.clear();
        cuisine_rating_food.clear();
        for(int i=0;i<foods.size();i++){
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_rating_food[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int prevRating = food_rating[food];
        cuisine_rating_food[cuisine].erase({-prevRating, food});
        food_rating[food] = newRating;
        cuisine_rating_food[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto itr = cuisine_rating_food[cuisine].begin();
        return (*itr).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */