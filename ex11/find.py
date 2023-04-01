import requests

# Ask user for the name of a Pokemon
pokemon_name = input("Enter the name of a Pokemon: ")

# Make a GET request to the PokeAPI with the Pokemon name
response = requests.get(f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}")

# Check if the request was successful
if response.status_code == 200:
    # Retrieve the Pokemon's abilities from the API response
    abilities = [ability["ability"]["name"] for ability in response.json()["abilities"]]
    
    # Display the Pokemon's name and abilities
    print(f"Name: {pokemon_name.capitalize()}")
    print("Abilities:")
    for ability in abilities:
        print(f"- {ability.capitalize()}")
else:
    # If the request was unsuccessful, display an error message
    print(f"Error: Could not retrieve information for {pokemon_name.capitalize()}.")
