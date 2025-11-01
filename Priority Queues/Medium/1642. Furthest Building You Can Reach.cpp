    for (int i = 0; i < heights.size() - 1; i++) {
        int diff = heights[i + 1] - heights[i];

        if (diff > 0) {
            // Store the climb
            minHeap.push(diff);

            // If we used more ladders than available, use bricks for the smallest climb
            if (minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();

                // If bricks become negative, we can't go further
                if (bricks < 0)
                    return i;
            }
        }
    }
