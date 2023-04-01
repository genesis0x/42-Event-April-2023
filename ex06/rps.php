<?php
// Get user's choice
$valid_choices = ['rock', 'paper', 'scissors'];
$user_choice = readline("Choose rock, paper, or scissors: ");

// Validate user's choice
if (!in_array($user_choice, $valid_choices)) {
  echo "Invalid choice. Please choose either rock, paper, or scissors.\n";
  exit;
}

// Generate computer's choice
$computer_choice = $valid_choices[array_rand($valid_choices)];

// Determine the winner
if ($user_choice == $computer_choice) {
  echo "It's a tie! The computer also chose $computer_choice.\n";
} elseif (
  ($user_choice == 'rock' && $computer_choice == 'scissors') ||
  ($user_choice == 'paper' && $computer_choice == 'rock') ||
  ($user_choice == 'scissors' && $computer_choice == 'paper')
) {
  echo "Congratulations! You won! The computer chose $computer_choice.\n";
} else {
  echo "Sorry, you lost. The computer chose $computer_choice.\n";
}
?>
