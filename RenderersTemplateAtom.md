### Atom syndication example ###


Representation element

To configure GeoREST to render template files as **Atom** add **Representation element** to the restcfg.xml file.
Set the **renderer** attribute of this element to value **"Template"**, **pattern** attribute to value **".atom"** and **mimetype** attribute to value **"application/atom+xml"**.
Details about configuring are found in [Configuration](Configuration.md) part of documentation.


Example configuration of the **Representation renderer**:
```
 <Representation renderer="Template" pattern=".atom" mimetype="application/atom+xml" >
   <Many file="propertyAtom.tpl" />
   <Single file="propertyAtom.tpl" />
   <None file="propertyAtomNone.tpl" />
   <Error file="propertyAtomError.tpl" />
 </Representation>
```

Example of the propertyAtom.tpl file:
```
<?xml version="1.0" encoding="utf-8"?>
 <feed xmlns="http://www.w3.org/2005/Atom">
 <title>Property atom view</title>
 {{#PROPERTY}}
 <entry>
   <title>Property {{PROPERTY_Autogenerated_SDF_ID}}</title>
   <updated>{{PROPERTY_DateModified_ATOM_DATE}}</updated>
   <id>urn:uuid:{{PROPERTY_Autogenerated_SDF_ID}}</id>
   <summary type="xhtml">
   <div xmlns="http://www.w3.org/1999/xhtml">
  	<table>
	<tbody>
	  <tr>
		<td>ID</td>
		<td>{{PROPERTY_Autogenerated_SDF_ID}}</td>
	  </tr>
	  <tr>
		<td>Address</td>
		<td>{{PROPERTY_RPROPAD}}</td>
	  </tr>
	</tbody>
	</table>
   </div>
   </summary>
 </entry>
{{/PROPERTY}}
</feed>
```