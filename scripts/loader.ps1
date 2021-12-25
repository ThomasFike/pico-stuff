# This script should be called from the root of a set of projects. Each folder should contain a build folder

# If a argument was sent then handle it and don't do dialog
param ($Project)
if ($Project -ne $null) {
  cd $Project
  $project_folders = Get-ChildItem -Attributes Directory -Exclude $exclude_list -Name -Filter build
  if (($project_folders | measure | % {$_.Count}) -eq 1) {
    $scripts_path = $PSScriptRoot + '\load.ps1'
    invoke-expression -Command $scripts_path
    if ($LASTEXITCODE -eq 0) {
      cd ..
      Write-Output 'Loaded!'
    } else {
      Write-Output 'Error: Could not find Pico'
    }
  } else {
    Write-Output "Build directory could not be located"
  }
  cd ..
  exit
}

Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

$form = New-Object System.Windows.Forms.Form
$form.Text = 'Select a Project'
$form.Size = New-Object System.Drawing.Size(300,200)
$form.StartPosition = 'CenterScreen'

$okButton = New-Object System.Windows.Forms.Button
$okButton.Location = New-Object System.Drawing.Point(150,120)
$okButton.Size = New-Object System.Drawing.Size(75,23)
$okButton.Text = 'Continue->'
$okButton.DialogResult = [System.Windows.Forms.DialogResult]::OK
$form.AcceptButton = $okButton
$form.Controls.Add($okButton)

$cancelButton = New-Object System.Windows.Forms.Button
$cancelButton.Location = New-Object System.Drawing.Point(75,120)
$cancelButton.Size = New-Object System.Drawing.Size(75,23)
$cancelButton.Text = 'Cancel'
$cancelButton.DialogResult = [System.Windows.Forms.DialogResult]::Cancel
$form.CancelButton = $cancelButton
$form.Controls.Add($cancelButton)

$label = New-Object System.Windows.Forms.Label
$label.Location = New-Object System.Drawing.Point(10,20)
$label.Size = New-Object System.Drawing.Size(280,20)
$label.Text = 'Please select the project you would like to load:'
$form.Controls.Add($label)

$dropdown = New-Object System.Windows.Forms.ComboBox
$dropdown.Location = New-Object System.Drawing.Point(10,40)
$dropdown.Size = New-Object System.Drawing.Size(260,20)
$dropdown.Height = 5

$exclude_list = @('scripts', 'pico-sdk', 'pico-examples', '.*')
$projects = Get-ChildItem -Attributes Directory -Exclude $exclude_list -Name
foreach ($item in $projects) {
  $dropdown.Items.Add($item)
}

$form.Controls.Add($dropdown)

$form.Topmost = $true

$result = $form.ShowDialog()

if ($result -ne [System.Windows.Forms.DialogResult]::OK) {
  exit
}
$selected = $dropdown.SelectedItem

cd $selected
$project_folders = Get-ChildItem -Attributes Directory -Exclude $exclude_list -Name -Filter build
if (($project_folders | measure | % {$_.Count}) -eq 1) {
  $scripts_path = $PSScriptRoot + '\load.ps1'
  invoke-expression -Command $scripts_path
  if ($LASTEXITCODE -eq 0) {
    cd ..
    $form = New-Object System.Windows.Forms.Form
    $form.Text = 'Device Flashed'
    $form.Size = New-Object System.Drawing.Size(500,100)
    $form.StartPosition = 'CenterScreen'
    
    $okButton = New-Object System.Windows.Forms.Button
    $okButton.Location = New-Object System.Drawing.Point(213,25)
    $okButton.Size = New-Object System.Drawing.Size(75,23)
    $okButton.Text = 'Ok'
    $okButton.DialogResult = [System.Windows.Forms.DialogResult]::OK
    $form.AcceptButton = $okButton
    $form.Controls.Add($okButton)
  
    $form.showDialog()
  } else {
    $form = New-Object System.Windows.Forms.Form
    $form.Text = 'Error: Could not find Pico'
    $form.Size = New-Object System.Drawing.Size(500,100)
    $form.StartPosition = 'CenterScreen'
    
    $okButton = New-Object System.Windows.Forms.Button
    $okButton.Location = New-Object System.Drawing.Point(213,25)
    $okButton.Size = New-Object System.Drawing.Size(75,23)
    $okButton.Text = 'Ok'
    $okButton.DialogResult = [System.Windows.Forms.DialogResult]::OK
    $form.AcceptButton = $okButton
    $form.Controls.Add($okButton)
  
    $form.showDialog()
  }
} else {
  $form = New-Object System.Windows.Forms.Form
  $form.Text = 'Error: Project does not have build folder'
  $form.Size = New-Object System.Drawing.Size(500,100)
  $form.StartPosition = 'CenterScreen'
  
  $okButton = New-Object System.Windows.Forms.Button
  $okButton.Location = New-Object System.Drawing.Point(213,25)
  $okButton.Size = New-Object System.Drawing.Size(75,23)
  $okButton.Text = 'Ok'
  $okButton.DialogResult = [System.Windows.Forms.DialogResult]::OK
  $form.AcceptButton = $okButton
  $form.Controls.Add($okButton)

  $form.showDialog()
}


cd ..