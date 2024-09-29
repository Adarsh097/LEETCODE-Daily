class FrequencyTracker {
    unordered_map<int, int> m;         // Tracks the frequency of each number
    unordered_map<int, int> freqCount; // Tracks how many numbers have a specific frequency

public:
    FrequencyTracker() {
        // Constructor
    }

    void add(int number) {
        int currentFreq = m[number];
        if (currentFreq > 0) {
            // Reduce the count of the old frequency
            freqCount[currentFreq]--;
            if (freqCount[currentFreq] == 0) {
                freqCount.erase(currentFreq); // Clean up to avoid unnecessary entries
            }
        }

        // Increment the frequency of the number
        m[number]++;
        freqCount[m[number]]++; // Increase the count of the new frequency
    }

    void deleteOne(int number) {
        if (m.find(number) != m.end() && m[number] > 0) {
            int currentFreq = m[number];
            // Reduce the count of the current frequency
            freqCount[currentFreq]--;
            if (freqCount[currentFreq] == 0) {
                freqCount.erase(currentFreq); // Clean up
            }

            // Decrease the frequency of the number
            m[number]--;
            if (m[number] == 0) {
                m.erase(number); // Remove the number if its frequency becomes zero
            } else {
                freqCount[m[number]]++; // Update frequency count
            }
        }
    }

    bool hasFrequency(int frequency) {
        // Check if any number has the given frequency in O(1)
        return freqCount.find(frequency) != freqCount.end();
    }
};
