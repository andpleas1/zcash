#include <gtest/gtest.h>

#include "metrics.h"
#include "utiltime.h"


TEST(Metrics, GetLocalSolPS) {
    SetMockTime(100);
    miningTimer.start();

    // No time has passed
    EXPECT_EQ(0, GetLocalSolPS());

    // Increment time
    SetMockTime(101);
    EXPECT_EQ(0, GetLocalSolPS());

    // Increment solutions
    solutionTargetChecks.increment();
    EXPECT_EQ(1, GetLocalSolPS());

    // Increment time
    SetMockTime(102);
    EXPECT_EQ(0.5, GetLocalSolPS());

    // Increment solutions
    solutionTargetChecks.increment();
    solutionTargetChecks.increment();
    EXPECT_EQ(1.5, GetLocalSolPS());

    // Stop timing
    miningTimer.stop();
    EXPECT_EQ(1.5, GetLocalSolPS());

    // Increment time
    SetMockTime(103);
    EXPECT_EQ(1.5, GetLocalSolPS());

    // Start timing again
    miningTimer.start();
    EXPECT_EQ(1.5, GetLocalSolPS());

    // Increment time
    SetMockTime(104);
    EXPECT_EQ(1, GetLocalSolPS());
}
