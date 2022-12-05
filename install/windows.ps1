# Copyright (c) 2022-present TheStngularity

# Information
Write-Output "SyrDB Installer for Windows v0.0.1"
Write-Output ""

# Fetch version
Write-Output "Fetching latest version of SyrDB..."
$version = (Invoke-RestMethod "https://api.github.com/repos/TheStngularity/SyrDB/releases")[0].tag_name

# Fetch asset
Write-Output "Fetching asset..."
$assets = (Invoke-RestMethod "https://api.github.com/repos/TheStngularity/SyrDB/releases/tags/${version}").assets
foreach($asset in $assets) {
    if($asset.name.EndsWith(".exe")) {
        $downloadUrl = $asset.browser_download_url
    }
}

# Download
Write-Output "Try to download latest release for Windows.."
Invoke-WebRequest $downloadUrl -OutFile "syrdb.exe"
Write-Output "Windows latest release downloaded!"