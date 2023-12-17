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
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            food_rating[food] = rating;
            food_cuisine[food] = cuisine;
            cuisine_rating_food[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int prevRating = food_rating[food];
        cuisine_rating_food[cuisine].erase({-prevRating,food});
        food_rating[food] = newRating;
        cuisine_rating_food[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto itr = cuisine_rating_food[cuisine].begin();
        string hRatedFood = (*itr).second;
        return hRatedFood;
    }
};



/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */