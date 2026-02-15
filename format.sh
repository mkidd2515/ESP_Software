

find src -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -i {} +

find include -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -i {} +

