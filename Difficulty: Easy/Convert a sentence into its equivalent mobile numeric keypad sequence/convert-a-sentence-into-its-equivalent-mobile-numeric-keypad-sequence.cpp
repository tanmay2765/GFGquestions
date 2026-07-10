string printSequence(string S) {
    string map[] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };
    string result = "";
    for (char ch : S) {
        if (ch == ' ') {
            result += "0";
        } else {
            int index = ch - 'A';
            result += map[index];
        }
    }
    return result;
}