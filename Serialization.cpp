#include <iostream>                                                          // For standard input/output operations
#include <string>                                                            // For using std::string
#include <boost/property_tree/ptree.hpp>                                     // Boost Property Tree for hierarchical data storage
#include <boost/property_tree/json_parser.hpp>                               // For JSON read/write functionality

int main() {
    using boost::property_tree::ptree;                                       // Alias for Boost ptree for readability
    ptree root;                                                              // Root of the JSON tree
    int n; 
    std::cout << "How many interns are working = ";                          // Prompt user for number of interns
    std::cin >> n; // Read number of interns
    std::cin.ignore();                                                       // Clear the input buffer to allow getline for strings

    ptree interns_array;                                                     // Create a ptree to store multiple intern objects

    for (int i = 0; i < n; i++) {

        ptree Intern;                                                        // Create ptree for individual intern

        std::string name, work, duration;
        std::cout << "\nIntern " << (i + 1) << " name: "; 
        std::getline(std::cin, name);                                        // Input intern name
        std::cout << "Duration of work (in months): "; 
        std::getline(std::cin, duration);                                    // Input duration of internship
        std::cout << "Work Assign: "; 
        std::getline(std::cin, work);                                        // Input assigned work

        Intern.put("name", name);                                            // Add name to intern object
        Intern.put("duration", duration);                                    // Add duration
        Intern.put("work", work);                                            // Add work assignment
        interns_array.push_back(std::make_pair("", Intern));                 // Add intern object to array
    }

    root.add_child("Interns Data", interns_array);                           // Attach interns array to root with key

    boost::property_tree::write_json(std::cout, root);                       // Print JSON to console
    boost::property_tree::write_json("interns.json", root);                  // Save JSON to file

    return 0;                                                                // Exit program
}
