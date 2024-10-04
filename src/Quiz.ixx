export module QuizModule;

import <vector>;
import <string>;
import <cstddef>;

export struct Quiz {
    std::string topic;
    std::vector<std::string> questions;
    std::byte answers;
};