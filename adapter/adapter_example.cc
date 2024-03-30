#include <iostream>

#include "adapt_legacy_rectangle.hh"
#include "legacy_rectangle.hh"

int main()
{
    LegacyRectangle adaptee = LegacyRectangle(8, 2, 5, 6);
    AdaptLegacyRectangle adapter = AdaptLegacyRectangle(adaptee);
    adapter.print();

    std::cout << adapter.area();
}
