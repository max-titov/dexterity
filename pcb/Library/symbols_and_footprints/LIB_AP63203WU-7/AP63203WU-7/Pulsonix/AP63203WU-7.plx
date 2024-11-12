PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//1863283/1506924/2.50/6/2/Integrated Circuit

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r100_70"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.700) (shapeHeight 1.000))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "AP63203WU7" (originalName "AP63203WU7")
		(multiLayer
			(pad (padNum 1) (padStyleRef r100_70) (pt -0.950, -1.099) (rotation 0))
			(pad (padNum 2) (padStyleRef r100_70) (pt 0.000, -1.099) (rotation 0))
			(pad (padNum 3) (padStyleRef r100_70) (pt 0.950, -1.099) (rotation 0))
			(pad (padNum 4) (padStyleRef r100_70) (pt 0.950, 1.099) (rotation 0))
			(pad (padNum 5) (padStyleRef r100_70) (pt 0.000, 1.099) (rotation 0))
			(pad (padNum 6) (padStyleRef r100_70) (pt -0.950, 1.099) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0.000, 0.000) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.45 -0.8) (pt 1.45 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.45 -0.8) (pt 1.45 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.45 0.8) (pt -1.45 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.45 0.8) (pt -1.45 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.45 2.599) (pt 2.45 2.599) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.45 2.599) (pt 2.45 -2.599) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 2.45 -2.599) (pt -2.45 -2.599) (width 0.1))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -2.45 -2.599) (pt -2.45 2.599) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.45 0.4) (pt -1.45 -0.4) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.45 0.4) (pt 1.45 -0.4) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.95 -2) (pt -0.95 -2) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -0.95, -2.05) (radius 0.05) (startAngle 90.0) (sweepAngle 180.0) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.95 -2.1) (pt -0.95 -2.1) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -0.95, -2.05) (radius 0.05) (startAngle 270) (sweepAngle 180.0) (width 0.1))
		)
	)
	(symbolDef "AP63203WU-7" (originalName "AP63203WU-7")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 1000 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 770 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 5) (pt 1000 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 770 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 6) (pt 1000 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 770 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 800 mils 100 mils) (width 6 mils))
		(line (pt 800 mils 100 mils) (pt 800 mils -300 mils) (width 6 mils))
		(line (pt 800 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 850 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 850 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "AP63203WU-7" (originalName "AP63203WU-7") (compHeader (numPins 6) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "FB") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "EN") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "VIN") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "4" (pinName "GND") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "5" (pinName "SW") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "6" (pinName "BST") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "AP63203WU-7"))
		(attachedPattern (patternNum 1) (patternName "AP63203WU7")
			(numPads 6)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
			)
		)
		(attr "Mouser Part Number" "621-AP63203WU-7")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Diodes-Incorporated/AP63203WU-7?qs=u16ybLDytRZ1JqxbuLkMJw%3D%3D")
		(attr "Manufacturer_Name" "Diodes Incorporated")
		(attr "Manufacturer_Part_Number" "AP63203WU-7")
		(attr "Description" "Switching Voltage Regulators DCDC Conv HV Buck TSOT26 T&R 3K")
		(attr "<Hyperlink>" "https://www.diodes.com/assets/Datasheets/AP63200-AP63201-AP63203-AP63205.pdf")
		(attr "<Component Height>" "1")
		(attr "<STEP Filename>" "AP63203WU-7.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=90;Y=0;Z=90")
	)

)