<?php

// php in windows complains without this
date_default_timezone_set("America/Los_Angeles");

// start the sql file
$file = fopen("phrases.sql", "w");
fwrite($file, "CREATE TABLE phrases (id INTEGER PRIMARY KEY AUTOINCREMENT,phrase TEXT);\n");

$phrases = file_get_contents("phrases_84_chars.txt");
$phrases = explode("\n", $phrases);
$count = 0;
foreach($phrases as $phrase) {
	$phrase = trim($phrase);
	if(!empty($phrase)) {
		if(strlen($phrase) <= 72) {
			// word wrap it, 18 chars a line, up to 4 lines
			
			/* A LOST OUNCE OF GOLD MAY BE FOUND, A LOST MOMENT OF TIME NEVER
			 * ['gold','may','be','found,'a','lost','moment','of','time','never']
			 * $col = 16;
			 * $row = 0;
			*/
			
			
			$width = 18; $height = 4;
			$words = explode(" ", $phrase);
			$col = 0;
			$row = 0;
			$all_good = true;
			foreach($words as $word) {
				if(strlen($word) >= $width) $all_good = false;
				$col += strlen($word);
				if($col >= $width) {
					$col = strlen($word)+1;
					$row++;
					if($col == $width) $col--;
					/*if($col == $width) {
						$col = 0;
						$row++;
					}*/
					if($row >= $height) $all_good = false;
				} else {
					$col++; // for the " "
					if($col >= $width) {
						$col = 0;
						$row++;
						if($row >= $height) $all_good = false;
					}
				}
			}
			if($all_good) {
				echo $phrase."\n";
				$count++;
				
				$sql = "INSERT INTO phrases (id,phrase) VALUES('".$count."','".sqlite_escape_string($phrase)."');\n";
				echo $sql;
				fwrite($file, $sql);
			}
		}
	}
}
echo "count: ".$count;

fclose($file);
