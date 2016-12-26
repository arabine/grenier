<?xml version="1.0" encoding="ISO-8859-1"?>

<!DOCTYPE FBskills [
ENTITY lskills SYSTEM "../data/skills.xml"
]>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head><title>Fantasy Bowl Roster</title></head>
      <body>


<p>


Equipe : <xsl:value-of select="FBteam/name" /><br />
Race : <xsl:value-of select="FBteam/race" /><br />
Coach : <xsl:value-of select="FBteam/coach" /><br />
Rating : <xsl:value-of select="FBteam/rating" /><br />
Treasury : <xsl:value-of select="FBteam/treasury" /><br />
Reroll cost : <xsl:value-of select="FBteam/@cost" /><br />
Rerolls : <xsl:value-of select="FBteam/reroll" /><br />
Fan factor : <xsl:value-of select="FBteam/fanfactor" /><br />
Assistants : <xsl:value-of select="FBteam/assistants" /><br />
Cheerleaders : <xsl:value-of select="FBteam/cheerleaders" /><br />
Apothecary : <xsl:value-of select="FBteam/apothecary" /><br />
Wizards : <xsl:value-of select="FBteam/wizard" /><br />
</p>

<!--<img src="../logos/<xsl:value-of select="logo" />">-->

 <table border="1" bgcolor="#666666" bordercolorlight="#000000" bordercolordark="#000000" cellpadding="2" cellspacing="2" width="80%" style="color: #000000; font-family: Arial, Helvetica, sans-serif;">
 <tr bgcolor="#c0c0c0"><th>#</th><th>Player Name</th><th>Position</th><th>ma</th><th>st</th><th>ag</th><th>av</th><th>Player Skills</th><th>INJ</th><th>COM</th><th>TD</th><th>INT</th><th>CAS</th><th>MVP</th><th>SPP</th><th>Cost</th></tr>   
     
     
     <xsl:for-each select="FBteam/player">
     
     <tr bgcolor="#c0c0c0" align="center">
     	<td><xsl:value-of select="@id" /></td>
     	<td><xsl:value-of select="name" /></td>
     	<td><xsl:value-of select="position" /></td>
     	<td><xsl:value-of select="ma" /></td>
     	<td><xsl:value-of select="st" /></td>
     	<td><xsl:value-of select="ag" /></td>
     	<td><xsl:value-of select="av" /></td>
     	<td><xsl:value-of select="skills" /></td>
     	<td>0</td>
     	<td>0</td>
     	<td>0</td>
     	<td>0</td>
     	<td>0</td>
     	<td>0</td>
     	<td>0</td>
     	<td align="right"><xsl:value-of select="cost" /></td>
     </tr>
     
     </xsl:for-each>
     
 </table>
      
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>