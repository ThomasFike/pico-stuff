$application_name = "my_led"

# Get the drives and check that only one was found
$possible_drives = Get-Volume | Where-Object -FilterScript {$_.FileSystemLabel -like "RPI-RP2"}
if (($possible_drives | measure | % {$_.Count}) -eq 1) {
} else {
  Write-Output "There is more then 1 Pico Looking Device connected"
  Write-Output "Connected Options:"
  $possible_drives
  exit
}

$drive_letter = $possible_drives.DriveLetter