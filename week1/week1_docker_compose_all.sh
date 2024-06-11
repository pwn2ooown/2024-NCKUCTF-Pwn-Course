#!/bin/bash

# Define the list of challenges
challenges=(
    "got"
    "got_adv"
    "magicgdb"
    "ret2sc"
    "ret2sc_adv"
    "ret2win"
    "ret2win_adv"
)

# Loop through the challenges
for challenge in "${challenges[@]}"; do
    echo "Entering challenge directory: $challenge"
    cd "$challenge"

    # Check if the "chal" directory exists
    if [ -d "chal" ]; then
        echo "Entering chal directory"
        cd "chal"

        # Run docker-compose up -d
        echo "Running docker-compose up -d"
        docker-compose up -d

        # Go back to the parent directory
        cd ..
    else
        echo "chal directory not found for $challenge"
    fi

    # Go back to the parent directory
    cd ..
done