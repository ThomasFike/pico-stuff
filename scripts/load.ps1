# Precondition: This script assumes that the root for a project is the current location.
# Precondition: The project also needs to currently be compiled

# Get the drives and check that only one was found
$possible_drives = Get-Volume | Where-Object -FilterScript {$_.FileSystemLabel -like "RPI-RP2"}
if (($possible_drives | measure | % {$_.Count}) -eq 1) {
} else {
  Write-Output "There is more then 1 Pico Looking Device connected"
  Write-Output "Connected Options:"
  $possible_drives
  exit 1
}

$drive_letter = $possible_drives.DriveLetter

cd build
$pico_path = $drive_letter + ":\"
$local_path = Get-Location
$local_path = $local_path.tostring() + "\*"
Copy-Item -Filter *.uf2 -Path $local_path -Destination $pico_path
exit 0