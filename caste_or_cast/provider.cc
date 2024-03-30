#include "provider.hh"

#include <iostream>

#include "nurturer.hh" //FIXME ???
#include "queen.hh"

void Provider::transferFood(Nurturer& nurturer)
{
    if (food_stock_ >= 1)
    {
        int whole = static_cast<int>(food_stock_);
        food_stock_ -= whole;
        nurturer.increment_food_stock_by(whole);

        std::cout << "Transferring food.\n";
    }
}

void Provider::harvestFood()
{
    float harversted_food = luck_;

    std::cout << "Harvested " << luck_ << " food.\n";

    food_stock_ += harversted_food;

    int whole = static_cast<int>(harversted_food);
    float decimal = harversted_food - whole;

    food_level_ -= (decimal / 2);
}

void Provider::work()
{
    if (stage_ == DevelopmentStage::ADULT)
    {
        int whole = static_cast<int>(food_stock_);
        float decimal = food_stock_ - whole;

        food_level_ += decimal;
        food_stock_ -= decimal;

        harvestFood();

        Worker::work();
    }
}

bool Provider::communicate(std::weak_ptr<Ant> wk_receiver)
{
    if (Ant::communicate(wk_receiver))
    {
        std::cout << "Provider initiates communication.\n";

        Ant* a = wk_receiver.lock().get();

        Queen* queen = dynamic_cast<Queen*>(a);
        Nurturer* nurturer = dynamic_cast<Nurturer*>(a);
        Provider* provider = dynamic_cast<Provider*>(a);

        if (nurturer != nullptr)
        {
            transferFood(*nurturer);
            return true;
        }

        return queen != nullptr || provider != nullptr;
    }
    return false;
}
