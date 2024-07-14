import subprocess

def run_command():
    try:
        # Running the command using subprocess
        result = subprocess.run(['cat', '/proc/kallsyms'], capture_output=True, text=True)
        
        # Checking if the command was successful
        if result.returncode == 0:
            # Filtering the result to find lines containing 'sys_call_table'
            lines = result.stdout.splitlines()
            filtered_lines = [line for line in lines if 'sys_call_table' in line]
            
            # Printing the filtered lines
            for line in filtered_lines:
                print(line)
        else:
            print(f"Command failed with return code {result.returncode}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    run_command()

